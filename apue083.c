//umask函数实例  复习一下creat函数
//2015-05-12
//by chandler

#include <fcntl.h>    //creat函数
#include <sys/stat.h> //umask函数
#include <stdio.h>

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)
int main()
{
	umask(0);
	if (creat("foo",RWRWRW) < 0)
		printf("creat error for foo\n");
	umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if (creat("bar",RWRWRW) < 0)
		printf("creat error for bar\n");
	
	return 0;
}
