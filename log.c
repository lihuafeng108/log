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
	//windows文件的换行符是"/r/n",与linux还是有点不一样，所以判断如果结束符是'\n'则更换为"/r/n"，如果没有结束符，则自动帮它增加
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
	

	fwrite(dis_buf, 1, strlen(dis_buf), gs_wr);  //把dis_buf的内容写到文件里面去
}

