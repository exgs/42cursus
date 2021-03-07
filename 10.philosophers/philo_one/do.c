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
	pthread_mutex_unlock(&g_info.print_mutex);
	if (ret == CONTINUE)
		return (CONTINUE);
	else if (ret == END)
		return (END);
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

		/*모니터링이라서 뮤텍스를 사용하면 안됨. 계속 판단해야돼*/
	while (1)
	{
		// 철학자 중 한명이라도 죽었을 때는 모니터링 쓰레드 종료
		if (g_info.anyone_dead == TRUE)
			break;
		// 철학자가 모두 배부르게 먹었을 때는 모니터링 쓰레드 종료
		if (g_info.meal_full != 0 && is_all_philos_full() == true)
			break ;
		if (g_info.meal_full != 0 && g_info.meal_full <= philo->meal_num)
		{
			if (g_info.full_list[philo->whoami] != 1)
				g_info.full_list[philo->whoami] = 1;
		}
		// 철학자의 라이프타임 계산
		time = get_relative_time();
		// printf("philo[%d] time :%d philo->when_eat :%d\n", philo->whoami + 1 ,time, philo->when_eat);
		if (time - philo->when_eat > g_info.time_to_die)
		{
			doing(DEAD, philo, time); // 병렬적인 프로그램을 만들고 있기 때문에, mutex 밖에서 시간은 건네줘야함!
			// g_info.anyone_dead = TRUE; 없어도 print_doing에서 설정해준다.
			break;
		}
		accurate_sleep(5); // 무한루프의 과부화 덜기(3)
	}
}

//한명의 철학자의 행동을 정의한 함수
void *philo_do(t_philo *philo)
{
	pthread_t thread;
	pthread_create(&thread, NULL, monitoring, philo); //쓰레드안에 쓰레드가 돎. 철학자의 수 : n 이면, 2n 개 만큼 쓰레드가 도는중
	// 모니터링함수에서는 공유자원의 값을 감시하고 변경해줄 수 있다. 따라서 공유자원은 쓰레드에서 모두 접근 가능한 전역변수여야 한다.
	if (philo->whoami % 2 == 1)
		accurate_sleep(1);
	while (1)
	{
		if (eat(philo, &g_info) == END) // eat 함수안에 doing()가 있음. 먹는 과정속에서 출력해야하는 값이 많아서...
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
