/********************************************************************************************************
文件名称：mian.h
版权所有(c) 2017，汕大软件联盟

当前版本：Ver 1.0
作    者：lihf

内容说明：
        主函数模块，主要测试软件的glog日志功能，glog类似printf()函数，只是它把打印信息输出到本地文件，当
        软件运行的时候，运行状态的所有信息都可以保存到本地日志，那么我们做一些数据统计，问题分析等都是非
        常有意义的。

其他：  设置的知识点:
        (1) 文件的操作，fopen，fwrite等；
        (2) 函数和宏中的变参问题，va_list，va_start，va_end, 宏定义中可变参数"##"的应用；
        (3) makefile,这个makefile写得很简单，由浅入深，要熟悉大型软件，makefile还是要学习一下，毕竟他涉及
            整个项目的编译、链接等等，makefile是linux必经之路。

修改记录：
版本号	     日期        作者	        修改内容
--------    --------    --------    --------
1.0         2017.04.19  lihuafeng   创建
 ********************************************************************************************************/
#include <stdio.h>
#include <stdarg.h>

#include "typedef.h"
#include "log.h"


FILE *gs_wr = NULL;

int main(void)
{
	u8 get_char;

	gs_wr = fopen("log.txt", "a+");  //追加方式打开，文件存在则保留原内容，不存在则创建
	debug_log_init(gs_wr);
	

	glog("run start....");	  //故意测试结束符不是'\n'
	glog("汕大电子计算机校友联盟, 日期:%s %s\n", __DATE__, __TIME__ );
	printf("accept your command(q-退出程序, 其他无效):");
	while(1)
	{
		get_char = getchar();
		if( 'q' == get_char )
		{
			break;
		}
	}
	glog("out....\n");
	
	fclose(gs_wr);
	
}

