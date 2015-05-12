//access函数实例,实际用户,有效用户,设置ID等概念
//2015-05-12
//by chandler

#include <fcntl.h>    //open函数
#include <unistd.h>   //access函数
#include <stdio.h>

int main(int argc,char *argv[])
{
	if (argc != 2) {
		printf("usage:a.out <pathname>\n");
		return -1;
	}

	if (access(argv[1],R_OK) < 0)
		printf("access error for %s\n",argv[1]);
	else
		printf("read access OK\n");
	
	if (open(argv[1],O_RDONLY) < 0)
		printf("open error for %s\n",argv[1]);
	else
		printf("open for reading OK\n");

	return 0;
}
