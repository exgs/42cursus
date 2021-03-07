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
	else if(status == TAKEN)
		printf("has taken a fork\n");
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
	// printf("end?\n");
	sem_wait(g_info.print_sema); // 뮤텍스 락을 여기다가 걸어줘야 내가 원하는 만큼만 나온다.
	// 그러지 않으면, if문에 대한 판단에 따른 선고 결과가 적용되기도 전에, if문에 더 들어옴
	if (g_info.anyone_dead == TRUE)
	{
		sem_post(g_info.print_sema);
		return (END);
	}
	if (g_info.meal_full != 0 && is_all_philos_full() == true)
	{
		printf("[%lu] %d번째 철학자 : 잘 먹었습니다~\n", interval, philo->whoami + 1);
		sem_post(g_info.print_sema);
		// exit(0); 다른 쓰레드에 있는 잘 먹었습니다 가 출력되야할 것이 출력이 안됨
		return (END);
	}
	printf("[%lu] %d번째 철학자 : ", interval, philo->whoami + 1);
	ret = print_doing(status, philo);
	sem_post(g_info.print_sema);
	if (ret == CONTINUE)
		return (CONTINUE);
	if (ret == END)
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
		// 철학자 중 한명이라도 죽었을 때는 프로그램 종료
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
		if (time - philo->when_eat > g_info.time_to_die)
		{
			doing(DEAD, philo, time); // 병렬적인 프로그램을 만들고 있기 때문에, mutex 밖에서 시간은 건네줘야함!
			// g_info.anyone_dead = TRUE; -> print_doing() 에서 해줌. 없어도 됨.
			break;
		}
		accurate_sleep(5); // 무한루프의 과부화 덜기(3)
	}
}

//한명의 철학자의 행동을 정의한 함수
void *philo_do(void *param)
{
	t_philo *philo = (t_philo *)param;
	pthread_t thread;
	pthread_create(&thread, NULL, monitoring, philo); //쓰레드안에 쓰레드가 돎. 철학자의 수 : n 이면, 2n 개 만큼 쓰레드가 도는중
	// 모니터링함수에서는 공유자원의 값을 감시하고 변경해줄 수 있다. 따라서 공유자원은 쓰레드에서 모두 접근 가능한 전역변수여야 한다.
	if (philo->whoami % 2 == 0)
		accurate_sleep(1);
	while (1)
	{
		if (eat(philo, &g_info) == END)
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

// philo_one에서 내가 먹으면 양옆에 있는 사람이 못 먹는 상황과 다르게 먹는 수만 맞으면 됨 -> 세마포어
int eat(t_philo *philo, t_info *info)
{
	if (g_info.anyone_dead == TRUE)
		return (END);
	sem_wait(info->chosen_people);
	sem_wait(info->forks);
	if (END == doing(TAKEN, philo, get_relative_time()))
	{
		sem_post(info->forks);
		sem_post(info->chosen_people);
		return (END);
	}
	sem_wait(info->forks);
	if (END == doing(TAKEN, philo, get_relative_time()))
	{
		sem_post_all(info);
		return (END);
	}
	if (END == doing(EATING, philo, get_relative_time()))
	{
		sem_post_all(info);
		return (END);
	}
	philo->when_eat = get_relative_time();
	spend_time_of(EATING);
	sem_post_all(info);
	return (CONTINUE);
}

void sem_post_all(t_info *info)
{
	sem_post(info->forks);
	sem_post(info->forks);
	sem_post(info->chosen_people);
}
