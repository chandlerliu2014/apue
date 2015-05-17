//echoall程序,功能是回显所有命令行参数及全部环境表
//2015-05-17
//by chandler

#include <stdio.h>
#include <stdlib.h>  //在os X中，加上这个头文件之后，exit函数不报警告~

int main(int argc,char *argv[])
{
	int i;
	char **ptr;
	extern char **environ;

	for (i = 0;i < argc;i++) //回显所有命令行参数
		printf("argv[%d]: %s\n",i,argv[i]);
	
	for (ptr = environ; *ptr != 0;ptr++)
		printf("%s\n",*ptr);

	exit(0);
}
