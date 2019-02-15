#ifndef _LOG_H_
#define _LOG_H_

/*
GCC��ͬʱ֧�����µ���ʽ�ĺ궨��ʹ�ÿɱ����:
#define LOG(format, args...) fprintf(stdout, format, args)
��һ����Ҫע�⣬�����ĺ궨�岻��ʡ�Կɱ��������������Դ���һ���ղ����������б�Ҫ�ᵽ"##"���ӷ��ŵ��÷���
"##"�������Ƕ�token�������ӣ��������У�format��__VA_ARGS__��args����token��
���tokenΪ�գ���ô���������ӣ���������ʡ�Կɱ����(__VA_ARGS__��args)����������κ��������޸�
#define LOG(format, ...)     fprintf(stdout, format, ##__VA_ARGS__)
#define LOG(format, args...) fprintf(stdout, format, ##args)
�����ı�κ궨�岻�����Զ��������ʽ���������#ifdef #else #endif�����������Ҳ�ܷ��㣬
�������ʱ���������Ϣ����ʽ����ʱ���������������
#ifdef DEBUG
#define LOG(format, ...) fprintf(stdout, ">> "format"\n", ##__VA_ARGS__)
#else
#define LOG(format, ...)
#endif
�ڵ��Ի����£�LOG����һ���������꣬���Զ���ĸ�ʽ�����
�ڷ��������£�LOG����һ���պ꣬�����κ�����
*/

#define DEBUG_LOG_ENABLE   //������壬������־��Ϣ������ļ������û��������һ���պ�����һ�㷢����ʱ���������Ϣ�ص�
#ifndef DEBUG_LOG_ENABLE
	#define glog( fmt, arg... )
#else
	#define glog( fmt, arg... ) debug_log( __FILE__, __FUNCTION__, __LINE__, fmt, ##arg )
#endif

void debug_log_init( FILE *wr_fd );
void debug_log( const u8 *file, const u8 *function, int lineconst, char *fmt, ... );


#endif
