# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <stdbool.h>

/*
** *info->address = 10000;*info->address = 10000;*info->address = 10000;*info->address = 10000;
*info->address = 10000;*info->address = 10000;*info->address = 10000;*info->address = 10000;*info->address = 10000;
*/

typedef struct	s_threadinfo
{
	pthread_t	tid;  // 쓰레드 식별자
	int			idx;  // 쓰레드 인덱스
	int*		address; // 지역변수 포인터
}				t_threadinfo;


void *test(void *param)
{
	t_threadinfo *info = (t_threadinfo *)param;
	printf("thread idx: %d\n", info->idx);
	printf("pthread_self: %p\n", pthread_self());
	printf("param address : %p\n", info->address);
	printf("*info->address : %d\n", *info->address);
	// *info->address = 10000; // 다른 변수에 영향을 줌
	printf("-------------------\n");
	return (NULL);
}

int main()
{
	int count = 5;
	t_threadinfo info[5];
	int i = 0;
	while (i < count)
	{
		info[i].idx = i;
		info[i].address = &i;
		pthread_create(&(info[i].tid), NULL, test, (void *)&info[i]);
		printf("main Thread\n");
		// sleep(1);
		i++;
	}


	for (int i = 0; i < count; i++)
	{
		pthread_join(info[i].tid, NULL);
		i++;
	}
	return (1);
}
