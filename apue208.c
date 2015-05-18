//解释器文件初探
//2015-05-19
//by chandler

//一直出错，一直出现execl error，谁能告诉我这是为什么！！！！！
//懂了，这个testinterp文件得添加可执行权限才行，另外，注意输出参数

#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	pid_t pid;
	
	if ((pid = fork()) < 0) {
		printf("fork error\n");
	} else if (pid == 0) {
		if (execl("/Users/chandler/apue/testinterp","testinterp","myarg1","MY ARG2",(char *)0) < 0)
			printf("execl error\n");
	}
	if (waitpid(pid,NULL,0) < 0)
		printf("waitpid error\n");

	exit(0);
}
