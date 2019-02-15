#include <stdio.h>
#include <stdarg.h>

#include "typedef.h"
#include "log.h"


static FILE *gs_wr = NULL;


void debug_log_init( FILE *wr_fd )
{
	gs_wr = wr_fd;
}

void debug_log( const u8 *file, const u8 *function, int lineconst, char *fmt, ... )
{
	u8 dis_buf[1024] = {0};
	u8 *ptr = dis_buf;
	u32 len = 0;;

	len = sprintf( ptr, "[file:%s][fuction:%s()][line:%d]", file, function, lineconst );
	ptr += len;

	va_list args;
	va_start(args,fmt);
	len = vsprintf(ptr,fmt,args);
	va_end(args);
	ptr += len;

	//
	//windows�ļ��Ļ��з���"/r/n",��linux�����е㲻һ���������ж������������'\n'�����Ϊ"/r/n"�����û�н����������Զ���������
	//
	if( '\n' == *(ptr-1) )
	{
		*(ptr-1) = '\r';
		*ptr++   = '\n';   
		*ptr++   = '\0';
	}
	else
	{
		*ptr++   = '\r';
		*ptr++   = '\n';   
		*ptr++   = '\0';
	}
	

	fwrite(dis_buf, 1, strlen(dis_buf), gs_wr);  //��dis_buf������д���ļ�����ȥ
}

