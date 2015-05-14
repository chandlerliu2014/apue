//打印有关缓冲的状态信息
//2015-05-14
//by chandler

#include <stdio.h>

void pr_stdio(const char *,FILE *);
int  is_unbuffered(FILE *);
int  is_linebuffered(FILE *);
int buffer_size(FILE *);

int main(void)
{
	FILE *fp;
	
	fputs("enter any character\n",stdout);
	if (getchar() == EOF)
		printf("getchar error\n");
	fputs("one line to standard error\n",stderr);

	pr_stdio("stdin",stdin);
	pr_stdio("stdout",stdout);
	pr_stdio("stderr",stderr);

	if ((fp = fopen("/etc/passwd","r")) == NULL)
		printf("fopen error\n");
	if (getc(fp) == EOF)
		printf("getc error\n");
	pr_stdio("/etc/passwd",fp);

	return 0;
}

void pr_stdio(const char *name,FILE *fp)
{
	printf("stream = %s, ",name);
	if (is_unbuffered(fp))
		printf("unbuffered");
	else if (is_linebuffered(fp))
		printf("line buffered");
	else 
		printf("fully buffered");
	printf(",buffer size = %d\n",buffer_size(fp));
}

// The following is nonportable
//这个下面都是一些跟系统实现相关的东西,就没必要深究了吧~~
//但是缓存,流FILE的概念还是比较重要的

#if defined(_IO_UNBUFFERED)
int is_unbuffered(FILE *fp)
{
	return (fp->_flags & _IO_UNBUFFERED);
}

int is_linebuffere(FILE *fp)
{
	return (fp->_flags & _IO_LINE_BUF);
}

int buffer_size(FILE *fp)
{
	return (fp->_IO_buf_end - fp->_IO_buf_base);
}

#elif defined(_SNBF)

int is_unbuffered(FILE *fp)
{
	return (fp->_flags & __SNBF);
}

int is_linebuffered(FILE *fp)
{
	return (fp->_flags & __SLBF);
}

int buffer_size(FILE *fp)
{
	return (fp->_bf._size);
}
