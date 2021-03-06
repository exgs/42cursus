#include "philo.h"

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
	{
		eat_even(philo, info);
	}
	if (philo->whoami % 2 == 1)
	{
		eat_odd(philo, info);
	}
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
