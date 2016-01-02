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

#define DSD_PRINT_READ fprintf(stderr, "\033[31m")// ERR
#define DSD_PRINT_YELLOW fprintf(stderr, "\033[33m")// WARN
#define DSD_PRINT_WHITE fprintf(stderr, "\033[37m")// NOTICE
#define DSD_PRINT_BLUE fprintf(stderr, "\033[34m")// INFO
#define DSD_PRINT_GREEN fprintf(stderr, "\033[32m")// DEBUG

int log_level = DSD_ERR;

void time_in_microseconds(int n) 
{
	unsigned long long now;
	struct timeval tv;

	gettimeofday(&tv, NULL);

	now = ((unsigned long long)tv.tv_sec * 1000000LL) + tv.tv_usec;
	switch (n) {
		case 0: DSD_PRINT_READ; break;
		case 1: DSD_PRINT_YELLOW; break;
		case 2: DSD_PRINT_WHITE; break;
		case 3: DSD_PRINT_BLUE; break;
		case 4: DSD_PRINT_GREEN; break;
		default: return;
	}
  	fprintf(stderr, "%s:[%llu:%d]", log_level_names[n], now / 1000000, (int)(now % 1000000));
}

void dsd_set_log_level(int level)
{
	log_level = level;
}

int dsd_log_filter(int filter)
{
	int i;

	if (log_level & filter) {
		for (i = 0; i < DSD_COUNT; i++) {
			if (filter == (1 << i)) {
				time_in_microseconds(i);
				return 1;
			}
		}
	}

	return 0;
}
