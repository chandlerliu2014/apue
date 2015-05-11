//将标准输入复制到标准输出
//2015-05-11
//by chandler

//ps:我们可以理解为用read和write方法进行io操作是不带缓冲的,而BUFFSIZE是人工设立的一个缓冲区
//  更改BUFFSIZE的值,会发现程序的效率有明显的变化,可以与标准io库相比较,从而更好的理解io缓冲

#include <unistd.h>
#include <stdio.h>

#define BUFFSIZE 4096

int main()
{
	int n;
	char buf[BUFFSIZE];

	while ((n = read(STDIN_FILENO,buf,BUFFSIZE)) > 0)
		if (write (STDOUT_FILENO,buf,n) != n) {
			printf("write error\n");
			return -1;
		}

	if (n < 0) {
		printf("read error\n");
		return -1;
	}

	//如果n==0,则是读至文件结束EOF
	if (n == 0) {
		printf("read EOF\n");
	}

	return 0;
}
