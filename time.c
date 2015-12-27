#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/time.h>
#include "debug.h"

#define _DEBUG
#ifdef _DEBUG
#define dsd_debug(...)\
		time_in_microseconds();\
		idebug(__VA_ARGS__);
#define dsd_debug_raw(...) \
		time_in_microseconds();\
		idebug_raw(__VA_ARGS__);
#else
#define dsd_debug(...) {}
#define dsd_debug_raw(...) {}
#endif

void time_in_microseconds(void) {
	unsigned long long now;
	struct timeval tv;

	gettimeofday(&tv, NULL);
	now = ((unsigned long long)tv.tv_sec * 1000000LL) + tv.tv_usec;
	fprintf(stderr, "%llu:%d ", now / 1000000, (int)(now % 1000000));
}

int answer(void) {
    return 42;
}

int main(int argc, char const *argv[]) {
	int num = 34;
	char *str = "world";
	unsigned long long time = 1234;
	float f_num = 12.34;

	dsd_debug(f_num, time, num, str, answer());
	dsd_debug(time);
	dsd_debug(num);
	dsd_debug(str);
	dsd_debug(answer());

	return 0;
}