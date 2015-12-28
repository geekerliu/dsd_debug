#include <stdio.h>

#define _DEBUG
#include "debug.h"

int answer(void) {
    return 42;
}

int main(int argc, char const *argv[]) {
	int num = 34;
	unsigned long long l_num = 1234;
	char *str = "world";
	float f_num = 12.34;

	dsd_debug(f_num, l_num, num, str, answer());
	dsd_debug(l_num);
	dsd_debug(num);
	dsd_debug(str);
	dsd_debug(answer());

	return 0;
}