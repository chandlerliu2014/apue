//chdir函数实例,改变进程的当前工作目录,需要注意的是,只影响调用进程本身,而不影响其他进程
//2015-05-13
//by chandler

#include <unistd.h> //这是一个神奇的头文件
#include <stdio.h>

int main(void)
{
	if (chdir("/tmp") < 0)
		printf("chdir failed\n");
	printf("chdir to /tmp succeeded\n");
	return 0;
}
