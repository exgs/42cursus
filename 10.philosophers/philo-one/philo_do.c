#include "philo.h"

int spend_time_of(int doing)
{
	int ms;

	if (EATING)
		ms = g_info.time_to_eat;
	if (SLEEPING)
		ms = g_info.time_to_sleep;
	usleep(ms * 1000);
}

int print_doing(int status, t_philo *philo)
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

int doing(unsigned char status, t_philo *philo, unsigned long interval)
{
	int ret;
	pthread_mutex_lock(&g_info.print_mutex); // 뮤텍스 락을 여기다가 걸어줘야 내가 원하는 만큼만 나온다.
	// 그러지 않으면, if문에 대한 판단에 따른 선고 결과가 적용되기도 전에, if문에 더 들어옴
	if (g_info.anyone_dead == TRUE)
	{
		pthread_mutex_unlock(&g_info.print_mutex);
		return (END);
	}
	if (g_info.meal_full != 0 &&
			philo->meal_num >= g_info.meal_full)
	{
		printf("[%lu] %d번째 철학자 : 잘 먹고 빠지렵니다~\n", interval, philo->whoami + 1);
		pthread_mutex_unlock(&g_info.print_mutex);
		return (END);
	}
	printf("[%lu] %d번째 철학자 : ", interval, philo->whoami + 1);
	ret = print_doing(status, philo);
	if (ret == CONTINUE)
	{
		pthread_mutex_unlock(&g_info.print_mutex);
		return (CONTINUE);
	}
	if (ret == END)
	{
		pthread_mutex_unlock(&g_info.print_mutex);
		return (END);
	}
}

int eat(t_philo *philo, t_info *info)
{
	if (g_info.anyone_dead == TRUE)
		return (END);
	pthread_mutex_lock(&info->forks[philo->left_fork_num]);
	doing(LEFT_TAKEN, philo, get_relative_time());
	pthread_mutex_lock(&info->forks[philo->right_fork_num]);
	doing(RIGHT_TAKEN, philo, get_relative_time());
	doing(EATING, philo, get_relative_time());
	spend_time_of(EATING);
	pthread_mutex_unlock(&info->forks[philo->left_fork_num]);
	pthread_mutex_unlock(&info->forks[philo->right_fork_num]);
	// usleep(10); // 여기다 넣어줘야, 철학자가 죽을 확률이 내려감.
	return (CONTINUE);
}

void *monitoring(t_philo *philo)
{
	unsigned long time;

	while (1)
	{
		// pthread_mutex_lock(&g_info.print_mutex);
		// pthread_mutex_unlock(&g_info.print_mutex);
		if (g_info.anyone_dead == TRUE)
			break;
		if (g_info.meal_full == philo->meal_num &&
				g_info.meal_full != 0)
			break;
		time = get_relative_time();
		// printf("-----\n");
		// printf("time-when_eat : %lu\n", time - philo->when_eat);
		// printf("lifetime : %lu\n", g_info.time_to_die);
		if (time - philo->when_eat > g_info.time_to_die)
		{
			doing(DEAD, philo, time); // 그래서 시간은 건네줘야함
			break;
		}
	}
}

//한명의 철학자의 행동을 정의한 함수
void *philo_do(t_philo *philo)
{
	/* monitoring()가 들어가야한다. */
	// pthread_t thread;
	// pthread_create(&thread, NULL, monitoring, philo); //쓰레드안에 쓰레드가 도는 건가 아니면, 프로세스에서 쓰레드의 갯수가 하나 추가된건가??
	// 모니터링에서는 자원들을 모니터링한 후에 공유자원의 값을 변경시켜줘야하지 않나?? 그러면 공유자원은 전역변수여야하는거 아니야??
	// if (philo->whoami % 2 == 0)
	// 	usleep(1);
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
	// pthread_join(thread, NULL);
	return (NULL);
}
