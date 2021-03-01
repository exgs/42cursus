#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

typedef struct	s_info
{
	pthread_t	tid;  // 쓰레드 식별자
	int			idx;  // 쓰레드 인덱스
	int			n;
	int			done;  // 0이다가 n이 3을 초과하면 1로 바뀌는 변수
}				t_info;

void	*cnt_monitor1(void *in)
{
	t_info	*info = (t_info *)in;

	while (1)
	{
		if (3 < info->n)
		{
			info->done = 1;
			break ;
		}
	}
	return (NULL);
}

void	*cnt_increase(void *in)
{
	t_info	*info = (t_info *)in;
	pthread_t	tid;

	// 쓰레드의 n이 3이상인지 while문이 도는 동안에 monitoring 하는 쓰레드 생성
	pthread_create(&tid, NULL, cnt_monitor1, info);
	while (1)
	{
		// usleep(1);
		sleep(1); //쓰레드가 동시에 돌아가고 있음을 극명하게 보여주기위해서는
		if (info->n <= 3)
		{
			printf("%d. n : %d\n", info->idx,info->n);
			info->n++;
		}
		if (info->done)
			break ;
	}
	// 쓰레드의 n이 3이상인지 체크하는 쓰레드종료를 기다리는 함수
	pthread_join(tid, NULL);
	return (NULL);
}

int		main(void)
{
	t_info		info[3];

	for(int i=0; i<3; i++)
	{
		info[i].idx = i;  // 쓰레드 인덱스
		info[i].n = 0;
		info[i].done = 0;
	}
	/* 쓰레드가 없는 경우 by yunslee */
	// for(int i=0; i<3; i++)
	// 	cnt_increase(&info[i]);

	/*쓰레드가 있는 경우*/
	for(int i=0; i<3; i++)
		// 쓰레드 생성
		pthread_create(&info[i].tid, NULL, cnt_increase, &info[i]);
	for(int i=0; i<3; i++)
		// 쓰레드 종료를 기다리는 함수
		pthread_join(info[i].tid, NULL);
}
