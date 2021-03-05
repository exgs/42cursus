#include "philo.h"

void accurate_sleep(unsigned long milisecond)
{
	// int i = 0;
	// while (i < 10)
	// {
	// 	usleep(milisecond * 100);
	// 	i++;
	// }
	unsigned long	base;
	unsigned long	cur;
	// printf("milisecond %d\n", milisecond);
	base = get_absolute_time();
	while (1)
	{
		cur = get_absolute_time();
		if (milisecond < cur - base)
			return ;
		usleep(100);
	}
}

int spend_time_of(t_status doing)
{
	unsigned long milisecond;

	if (doing == EATING)
		milisecond = g_info.time_to_eat;
	if (doing == SLEEPING)
		milisecond = g_info.time_to_sleep;
	accurate_sleep(milisecond);
	// usleep(milisecond * 1000);
}

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
		return (END);
	}
	if (g_info.meal_full != 0 &&
			philo->meal_num >= g_info.meal_full)
	{
		printf("[%lu] %d번째 철학자 : 잘 먹고 빠지렵니다~\n", interval, philo->whoami + 1); // 이런 출력 부분도 꼬일 수 있으니 print_doing 않으로 넣는 것이 현명해보임.
		pthread_mutex_unlock(&g_info.print_mutex);
		return (END);
	}
	printf("[%lu] %d번째 철학자 : ", interval, philo->whoami + 1); // 이런 출력 부분도 꼬일 수 있으니 print_doing 않으로 넣는 것이 현명해보임.
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

// 짝수번째 철학자의 경우
void eat_even(t_philo *philo, t_info *info)
{
	pthread_mutex_lock(&info->forks[philo->left_fork_num]);
	doing(LEFT_TAKEN, philo, get_relative_time());
	pthread_mutex_lock(&info->forks[philo->right_fork_num]);
	doing(RIGHT_TAKEN, philo, get_relative_time());
	// printf("left: %d right: %d\n", philo->left_fork_num, philo->right_fork_num);
	philo->when_eat = get_relative_time();
	doing(EATING, philo, get_relative_time());
	spend_time_of(EATING);
	pthread_mutex_unlock(&info->forks[philo->left_fork_num]);
	pthread_mutex_unlock(&info->forks[philo->right_fork_num]);
}

// 홀수번째 철학자의 경우
void eat_odd(t_philo *philo, t_info *info)
{
	pthread_mutex_lock(&info->forks[philo->right_fork_num]);
	doing(RIGHT_TAKEN, philo, get_relative_time());
	pthread_mutex_lock(&info->forks[philo->left_fork_num]);
	doing(LEFT_TAKEN, philo, get_relative_time());
	// printf("left: %d right: %d\n", philo->left_fork_num, philo->right_fork_num);
	philo->when_eat = get_relative_time();
	doing(EATING, philo, get_relative_time());
	spend_time_of(EATING);
	pthread_mutex_unlock(&info->forks[philo->left_fork_num]);
	pthread_mutex_unlock(&info->forks[philo->right_fork_num]);
}

int eat(t_philo *philo, t_info *info)
{
	if (g_info.anyone_dead == TRUE)
		return (END);
	if (philo->whoami % 2 == 0)
		eat_even(philo, info);
	if (philo->whoami % 2 == 1)
		eat_odd(philo, info);
	// pthread_mutex_lock(&info->forks[philo->left_fork_num]);
	// doing(LEFT_TAKEN, philo, get_relative_time());
	// pthread_mutex_lock(&info->forks[philo->right_fork_num]);
	// doing(RIGHT_TAKEN, philo, get_relative_time());
	// doing(EATING, philo, get_relative_time());
	// philo->when_eat = get_relative_time();
	// spend_time_of(EATING);
	// pthread_mutex_unlock(&info->forks[philo->left_fork_num]);
	// pthread_mutex_unlock(&info->forks[philo->right_fork_num]);
	// usleep(10); // 여기다 넣어줘야, 철학자가 죽을 확률이 내려감.
	return (CONTINUE);
}

void *monitoring(t_philo *philo)
{
	unsigned long time;

	while (1)
	{
		/*모니터링이라서 뮤텍스를 사용하면 안됨. 계속 판단해야돼*/

		// 철학자 중 한명이라도 죽었을 때는 프로그램 종료
		if (g_info.anyone_dead == TRUE)
			break;
		// 지금 모니터링하고 있는 철학자가 배부르게 먹었을 때는 쓰레드 종료
		if (g_info.meal_full == philo->meal_num &&
				g_info.meal_full != 0)
			break;

		// 철학자가 굶어 죽는 상황인지 계산
		time = get_relative_time();
		// printf("philo[%d] time :%d philo->when_eat :%d\n", philo->whoami + 1 ,time, philo->when_eat);
		if (time - philo->when_eat > g_info.time_to_die)
		{
			doing(DEAD, philo, time); // 그래서 시간은 건네줘야함
			g_info.anyone_dead = TRUE;
			break;
		}
		accurate_sleep(10);
	}
}

//한명의 철학자의 행동을 정의한 함수
void *philo_do(t_philo *philo)
{
	/* monitoring()가 들어가야한다. */
	pthread_t thread;
	pthread_create(&thread, NULL, monitoring, philo); //쓰레드안에 쓰레드가 도는 건가 아니면, 프로세스에서 쓰레드의 갯수가 하나 추가된건가??
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
	pthread_join(thread, NULL);
	return (NULL);
}
