# dsd_debug
c语言调试宏
## 代码示例
```c
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/time.h>
#include "debug.h"

#define _DEBUG
#ifdef _DEBUG
#define dsd_debug(...) \
		time_in_microseconds();\
		idebug_raw(__VA_ARGS__);
#else
#define dsd_debug(...) {}
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

	dsd_debug("f_num=", f_num);
	dsd_debug("time=", time);
	dsd_debug(num);
	dsd_debug("hello", str);
	dsd_debug(answer());
	return 0;
}
```
## 输出内容
1451015934:433395 [main.c:35][main] f_num= 12.34
1451015934:433476 [main.c:36][main] time= 1234
1451015934:433491 [main.c:37][main] 34
1451015934:433504 [main.c:38][main] hello world
1451015934:433521 [main.c:39][main] 42
