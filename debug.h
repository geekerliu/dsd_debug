#ifndef _DSD_DEBUG_H
#define _DSD_DEBUG_H

enum dsd_log_levels {
  DSD_ERR = 1 << 0,
  DSD_WARN = 1 << 1,
  DSD_NOTICE = 1 << 2,
  DSD_INFO = 1 << 3,
  DSD_DEBUG = 1 << 4,

  DSD_COUNT =  6/* set to count of valid flags */
};

/**
 * 设置调试级别，表明哪些级别的信息可以打印出来
 */
void dsd_set_log_level(int level);
int dsd_log_filter(int filter);

#define dsdl_notice(format, args...) \
	do {\
		if (dsd_log_filter(DSD_NOTICE)) {\
			fprintf(stderr,"\033[35m" "[%s->%s->%d]-> " "\033[0m",__FILE__,__func__,__LINE__);\
			fprintf(stderr,"\033[35m" format "\033[0m", ##args);\
		}\
	}while(0)

#define dsdl_warn(format, args...) \
	do {\
		if (dsd_log_filter(DSD_WARN)) {\
			fprintf(stderr,"\033[33m" "[%s->%s->%d]-> " "\033[0m",__FILE__,__func__,__LINE__);\
			fprintf(stderr,"\033[33m" format "\033[0m", ##args);\
		}\
	}while(0)

#define dsdl_info(format, args...) \
	do {\
		if (dsd_log_filter(DSD_INFO)) {\
			fprintf(stderr, "\033[32m" "[%s->%s->%d]-> " "\033[0m",__FILE__,__func__,__LINE__);\
			fprintf(stderr, "\033[32m" format "\033[0m", ##args);\
		}\
	}while(0)

#define dsdl_debug(format, args...) \
	do {\
		if (dsd_log_filter(DSD_DEBUG)) {\
			fprintf(stderr, "[%s->%s->%d]-> ",__FILE__,__func__,__LINE__);\
			fprintf(stderr, format, ##args);\
		}\
	}while(0)

#define dsdl_err(format, args...) \
	do {\
		if (dsd_log_filter(DSD_ERR)) {\
			fprintf(stderr,"\033[31m" "[%s->%s->%d]-> " "\033[0m",__FILE__,__func__,__LINE__);\
			fprintf(stderr,"\033[31m" format "\033[0m", ##args);\
		}\
	}while(0)

#endif