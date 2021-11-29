#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct	s_info
{
	pthread_t	tid;  // 쓰레드 식별자
	int			idx;  // 쓰레드 인덱스
	int			n;
	bool		stop;  // 모니터링하다가 쓰레드를 멈추게하는 제어 변수
}				t_info;

void	*cnt_monitor1(void *in)
{
	t_info	*info = (t_info *)in;

	while (1)
	{
		if (info->n == 3)
		{
			info->stop = true;
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
		printf("%d. n : %d\n", info->idx,info->n);
		info->n++;
		if (info->stop == true)
			break ;
	}
	// 쓰레드의 n이 3이상인지 체크하는 쓰레드종료를 기다리는 함수
	pthread_join(tid, NULL);
	return (NULL);
}

void reset(t_info *info, int count)
{
	for (int i = 0; i < count; i++)
	{
		info[i].idx = i;  // 쓰레드 인덱스
		info[i].n = 0;
		info[i].stop = false;
	}
}

int		main(void)
{
	t_info		info[3];

	reset(info, 3);
	
	/* 쓰레드가 없는 경우는 동기 */
	// for(int i=0; i<3; i++)
	// 	cnt_increase(&info[i]);

	/* 쓰레드가 있는 경우는 비동기 */
	for(int i=0; i<3; i++)
		pthread_create(&info[i].tid, NULL, cnt_increase, &info[i]);
	for(int i=0; i<3; i++)
		pthread_join(info[i].tid, NULL);
}
