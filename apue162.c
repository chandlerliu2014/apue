//将所有命令行参数回显到标准输出
//2015-05-15
//by chandler

#include <stdio.h>

int main(int argc,char *argv[])
{
	int i;
	
	//for (i = 0;i < argc;i++)
	for (i = 0;argv[i] != NULL;i++)
		printf("argv[%d]: %s\n",i,argv[i]);

	exit(0);
}
