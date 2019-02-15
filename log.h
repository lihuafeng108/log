#ifndef _LOG_H_
#define _LOG_H_

/*
GCC中同时支持如下的形式的宏定义使用可变参数:
#define LOG(format, args...) fprintf(stdout, format, args)
有一点需要注意，上述的宏定义不能省略可变参数，尽管你可以传递一个空参数，这里有必要提到"##"连接符号的用法。
"##"的作用是对token进行连接，在上例中，format、__VA_ARGS__、args即是token，
如果token为空，那么不进行连接，所以允许省略可变参数(__VA_ARGS__和args)，对上述变参宏做如下修改
#define LOG(format, ...)     fprintf(stdout, format, ##__VA_ARGS__)
#define LOG(format, args...) fprintf(stdout, format, ##args)
上述的变参宏定义不仅能自定义输出格式，而且配合#ifdef #else #endif在输出管理上也很方便，
比如调试时输出调试信息，正式发布时则不输出，可以这样
#ifdef DEBUG
#define LOG(format, ...) fprintf(stdout, ">> "format"\n", ##__VA_ARGS__)
#else
#define LOG(format, ...)
#endif
在调试环境下，LOG宏是一个变参输出宏，以自定义的格式输出；
在发布环境下，LOG宏是一个空宏，不做任何事情
*/

#define DEBUG_LOG_ENABLE   //如果定义，则开启日志信息输出到文件，如果没定义则是一个空函数，一般发布的时候会把输出信息关掉
#ifndef DEBUG_LOG_ENABLE
	#define glog( fmt, arg... )
#else
	#define glog( fmt, arg... ) debug_log( __FILE__, __FUNCTION__, __LINE__, fmt, ##arg )
#endif

void debug_log_init( FILE *wr_fd );
void debug_log( const u8 *file, const u8 *function, int lineconst, char *fmt, ... );


#endif
