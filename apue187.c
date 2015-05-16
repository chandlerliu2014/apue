//vfork函数使用
//2015-05-16
//by chandler
//vfork和fork不同的地方在于，它在父进程空间执行，所以子进程中得改变父进程表现出来了
//另外一个不同的地方在于，vfork的子进程在父进程之前执行

#include <unistd.h>
#include <stdio.h>

int globvar = 6;

int main(void)
{
	int var;
	pid_t pid;

	var = 88;
	printf("before vfork\n");
	if ((pid = vfork()) < 0) {
		printf("vfork error\n");
	} else if (pid == 0) {
		globvar++;
		var++;
		exit(0);
	}

	printf("pid = %ld,glob = %d,var = %d\n",(long)getpid(),globvar,var);
	exit(0);
}
