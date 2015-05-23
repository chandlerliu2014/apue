//使用互斥量保护数据结构
//2015-05-23
//by chandler

//ps:好几天没写程序了，这两天办校区，办完实验室搬宿舍，已经快阵亡了，幸运的是江宁还是比较好的，我喜欢这儿，晚上坐在宿舍写程序，真是享受，so，apue，来吧

#include <stdlib.h>
#include <pthread.h>

struct foo {
	int f_count;
	pthread_mutex_t f_lock;
	int f_id;
};

struct foo *foo_alloc(int id)
{
	struct foo *fp;

	if ((fp = malloc(sizeof(struct foo))) != NULL) {
		fp->f_count = 1;
		fp->f_id = id;
		if (pthread_mutex_init(&fp->f_lock,NULL) != 0) {
			free(fp);
			return (NULL);
		}
	}
	return fp;
}

void foo_hold(struct foo *fp)
{
	pthread_mutex_lock(&fp->f_lock);
	fp->f_count++;
	pthread_mutex_unlock(&fp->f_lock);
}

void foo_rele(struct foo *fp)
{
	pthread_mutex_lock(&fp->f_lock);
	if (--fp->f_count == 0) {
		pthread_mutex_unlock(&fp->f_lock);
		pthread_mutex_destroy(&fp->f_lock);
		free(fp);
	} else {
		pthread_mutex_unlock(&fp->f_lock);
	}
}
