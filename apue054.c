//lseek函数用法实例
//2015-05-11
//by chandler

#include <unistd.h> //lseek,标准输入,输出,错误输出定义
#include <stdio.h>

int main()
{
	if (lseek(STDIN_FILENO,0,SEEK_CUR) == -1)
		printf("cannot seek\n");
	else
		printf("seek OK\n");
	return 0;
}
