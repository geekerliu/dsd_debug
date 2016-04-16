#include <stdio.h>
#include <sys/time.h>
#include "debug.h"

static const char * const log_level_names[] = {
	"ERR",
	"WARN",
	"NOTICE",
	"INFO",
	"DEBUG",
};

int log_level = DSD_ERR;

void dsd_time_in_microseconds(int n)
{
	unsigned long long now;
	struct timeval tv;

	gettimeofday(&tv, NULL);

	now = ((unsigned long long)tv.tv_sec * 1000000LL) + tv.tv_usec;
	fprintf(stderr, "%s:[%llu:%d]", log_level_names[n], now / 1000000, (int)(now % 1000000));
}

void dsd_set_log_level(int level)
{
	log_level = level;
}

int dsd_log_filter(int filter)
{
	int i = 0;

	if (log_level & filter) {
		for (i = 0; i < DSD_COUNT; i++) {
			if (filter == (1 << i)) {
				dsd_time_in_microseconds(i);
				return 1;
			}
		}
	}

	return 0;
}
