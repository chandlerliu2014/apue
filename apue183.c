//fork函数初探
//2015-05-16
//by chandler
//ps:这个例子主要是让我们理解子进程和父进程是什么个关系，但更有意思的是printf输出
//当输出到屏幕时，行缓冲，输出玩befor fork就冲洗了，但是如果输出到文件中，则不一样了，试试吧

#include <unistd.h>
#include <stdio.h>

int globval = 6;  //初始化了的全局变量，存储在数据区
char buf[] = "a write to stdout\n";

int main(void)
{
	int var;  //自动变量，存储在栈里
	pid_t pid;
	
	var = 88;
	if (write(STDOUT_FILENO,buf,sizeof(buf)-1) != sizeof(buf)-1)
		printf("write error\n");
	printf("befor fork\n");

	if ((pid = fork()) < 0) {
		printf("fork error\n");
	} else if (pid == 0) {
		globval++;
		var++;
	} else {
		sleep(2);
	}

	printf("pid = %ld,glob = %d,var = %d\n",(long)getpid(),globval,var);
	exit(0);
}
