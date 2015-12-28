# dsd_debug
c语言调试宏
## 代码示例
```c
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
```
## 输出内容
```
1451201741:12325 [time.c:39][main]
	f_num = 12.34
	time = 1234
	num = 34
	str = world
	answer() = 42
1451201741:12368 [time.c:40][main] time = 1234
1451201741:12372 [time.c:41][main] num = 34
1451201741:12375 [time.c:42][main] str = world
1451201741:12378 [time.c:43][main] answer() = 42
```
## 使用方法
```
#define _DEBUG
#include "debug.h"
//开始享受调试的乐趣吧 
```
