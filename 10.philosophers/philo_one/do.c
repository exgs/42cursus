#include "philo.h"



int print_doing(t_status status, t_philo *philo)
{
	if (status == EATING)
	{
		printf("is eating\n");
		philo->meal_num++;
	}
	else if(status == SLEEPING)
	{
		printf("is sleeping\n");
	}
	else if(status == THINKING)
		printf("is thinking\n");
	else if(status == RIGHT_TAKEN)
		printf("has taken a right fork\n");
	else if(status == LEFT_TAKEN)
		printf("has taken a left fork\n");
	else if(status == DEAD)
	{
		printf("is dead\n");
		g_info.anyone_dead = TRUE; 
		return (END);
	}
	return (CONTINUE);
}

int doing(t_status status, t_philo *philo, unsigned long interval)
{
	int ret;
	pthread_mutex_lock(&g_info.print_mutex); // 뮤텍스 락을 여기다가 걸어줘야 내가 원하는 만큼만 나온다.
	// 그러지 않으면, if문에 대한 판단에 따른 선고 결과가 적용되기도 전에, if문에 더 들어옴
	// interval = get_relative_time(); // mutex에 도착한 순서대로 하는게 맞는 걸까?? -> 출력으로만 보면 이게 더 맞는거 같아.
	if (g_info.anyone_dead == TRUE)
	{
		pthread_mutex_unlock(&g_info.print_mutex);
		// free_all() // 간단하게는 이렇게 해도 됨
		// exit(0); // 간단하게는 이렇게 해도 됨
		return (END);
	}
	if (g_info.meal_full != 0 && is_all_philos_full() == true)
	{
		printf("[%lu] %d번째 철학자 : 잘 먹었습니다~\n", interval, philo->whoami + 1);
		pthread_mutex_unlock(&g_info.print_mutex);
		// exit(0); 다른 쓰레드에 있는 잘 먹었습니다 가 출력되야할 것이 출력이 안됨
		return (END);
	}
	printf("[%lu] %d번째 철학자 : ", interval, philo->whoami + 1);
	ret = print_doing(status, philo);
	if (ret == CONTINUE)
	{
		pthread_mutex_unlock(&g_info.print_mutex);
		return (CONTINUE);
	}
	else if (ret == END)
	{
		pthread_mutex_unlock(&g_info.print_mutex);
		return (END);
	}
}

bool is_all_philos_full()
{
	int i = 0;
	int cnt = 0;
	while (i < g_philo_num)
	{
		if (g_info.full_list[i] == 1)
			cnt++;
		i++;
	}
	if (cnt == g_philo_num)
		return (true);
	else
		return (false);
}

void *monitoring(void *param)
{
	t_philo *philo = (t_philo *)param;
	unsigned long time;

	while (1)
	{
		/*모니터링이라서 뮤텍스를 사용하면 안됨. 계속 판단해야돼*/
		//만약 한다면???
		// 철학자 중 한명이라도 죽었을 때는 프로그램 종료
		if (g_info.anyone_dead == TRUE)
			break;
		// 지금 모니터링하고 있는 철학자가 모두 배부르게 먹었을 때는 쓰레드 종료
		if (g_info.meal_full != 0 && is_all_philos_full() == true)
			break ;
		if (g_info.meal_full != 0 && g_info.meal_full <= philo->meal_num)
		{
			if (g_info.full_list[philo->whoami] != 1)
				g_info.full_list[philo->whoami] = 1;
		}
		// 철학자가 굶어 죽는 상황인지 계산
		time = get_relative_time();
		// printf("philo[%d] time :%d philo->when_eat :%d\n", philo->whoami + 1 ,time, philo->when_eat);
		if (time - philo->when_eat > g_info.time_to_die)
		{
			// printf("what?\n");
			doing(DEAD, philo, time); // 그래서 시간은 건네줘야함
			// g_info.anyone_dead = TRUE; 없어도 print_doing에서 설정해준다.
			break;
		}
		accurate_sleep(5); // 이거 설정안해주면, 모니터링 쓰레드를 써도 완전 이상한 시간에 밥먹고 그런다.
	}
}

//한명의 철학자의 행동을 정의한 함수
void *philo_do(t_philo *philo)
{
	/* monitoring()가 들어가야한다. */
	//맹점1.
	pthread_t thread;
	pthread_create(&thread, NULL, monitoring, philo); //쓰레드안에 쓰레드가 도는 건가 아니면, 프로세스에서 쓰레드의 갯수가 하나 추가된건가??
	// 모니터링에서는 자원들을 모니터링한 후에 공유자원의 값을 변경시켜줘야하지 않나?? 그러면 공유자원은 전역변수여야하는거 아니야??
	if (philo->whoami % 2 == 1)
		accurate_sleep(1);
	while (1)
	{
		if (eat(philo, &g_info) == END) // 내부에 doing가 내장되어있음
			break;
		if (doing(SLEEPING, philo, get_relative_time()) == END)
			break ;
		spend_time_of(SLEEPING);
		if (doing(THINKING, philo, get_relative_time()) == END)
			break;
	}
	pthread_join(thread, NULL);
	return (NULL);
}
