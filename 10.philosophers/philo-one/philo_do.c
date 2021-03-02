#include "philo.h"


void *monitoring(void* param)
{
	return (NULL);
}

int spend_time(unsigned long ms)
{
	usleep(ms * 1000);
}

int print_status(unsigned char status, t_philo *philo, t_info *info)
{
	if (info->anyone_dead == TRUE)
		return (END);
	if (info->number_of_times_each_philosopher_must_eat != 0 &&
		info->number_of_times_each_philosopher_must_eat <= philo->meal_num)
		return (END);
	unsigned long interval;
	interval = get_basetime() - info->basetime;
	pthread_mutex_lock(&info->print_mutex); // 뮤텍스 락을 여기다가 걸어줘야 내가 원하는 만큼만 나온다.
	// if문에 대한 판단에 따른 선고 결과가 적용되기도 전에, if문에 더 들어옴
	if (info->number_of_times_each_philosopher_must_eat != 0 &&
			philo->meal_num >= info->number_of_times_each_philosopher_must_eat)
	{
		pthread_mutex_unlock(&info->print_mutex);
		return (END);
	}
	printf("[%lu] %d번째 철학자 : ", interval, philo->whoami + 1);
	if(status == EATING)
	{
		printf("is eating\n");
		spend_time(info->time_to_eat);
		philo->meal_num++;
		// printf("식사량=%d\n", philo->meal_num);
	}
	else if(status == SLEEPING)
	{
		printf("is sleeping\n");
		spend_time(info->time_to_sleep);
	}
	else if(status == THINKING)
		printf("is thinking\n");
	else if(status == TAKEN)
		printf("has taken a fork\n");
	pthread_mutex_unlock(&info->print_mutex);
	return (CONTINUE);
}

int eat(t_philo *philo, t_info *info)
{
	if (info->anyone_dead == TRUE)
		return (END);
	pthread_mutex_lock(&info->forks[philo->left_fork_num]);
	print_status(TAKEN, philo, info);
	pthread_mutex_lock(&info->forks[philo->right_fork_num]);
	print_status(TAKEN, philo, info);
	print_status(EATING, philo, info);
	pthread_mutex_unlock(&info->forks[philo->left_fork_num]);
	pthread_mutex_unlock(&info->forks[philo->right_fork_num]);
	return (CONTINUE);
}

//한명의 철학자의 행동을 정의한 함수
void *philo_do(t_philo *philo)
{
	/* monitoring()가 들어가야한다. */
	// pthread_t thread;
	// pthread_create(&thread, NULL, monitoring, temp?)
	// 모니터링에서는 자원들을 모니터링한 후에 공유자원의 값을 변경시켜줘야하지 않나?? 그러면 공유자원은 전역변수여야하는거 아니야??
	// if (philo->whoami % 2 == 0)
	// 	usleep(1);
	while (1)
	{
		if (eat(philo, &g_info) == END) // 내부에 print_status가 내장되어있음
			break;
		if (print_status(SLEEPING, philo, &g_info) == END)
			break ;
		if (print_status(THINKING, philo, &g_info) == END)
			break;
	}
	return (NULL);
}
