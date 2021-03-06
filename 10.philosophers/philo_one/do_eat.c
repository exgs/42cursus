#include "philo.h"


// 오른손부터 뻗기때문에, 결과적으로 못먹는 사람은 시계반대방향으로 이동함
int eat_one_direction(t_philo *philo, t_info *info) //악수
{
	pthread_mutex_lock(&info->forks[philo->right_fork_num]);
	if (END == doing(RIGHT_TAKEN, philo, get_relative_time()))
	{
		pthread_mutex_unlock(&info->forks[philo->right_fork_num]);
		return (END);
	}
	pthread_mutex_lock(&info->forks[philo->left_fork_num]);
	if (END == doing(LEFT_TAKEN, philo, get_relative_time()))
	{
		pthread_mutex_unlock(&info->forks[philo->left_fork_num]);
		return (END);
	}
	// printf("left: %d right: %d\n", philo->left_fork_num, philo->right_fork_num);
	philo->when_eat = get_relative_time();
	if (END == doing(EATING, philo, get_relative_time()))
	{
		pthread_mutex_unlock(&info->forks[philo->left_fork_num]);
		pthread_mutex_unlock(&info->forks[philo->right_fork_num]);
		return (END);
	}
	spend_time_of(EATING);
	pthread_mutex_unlock(&info->forks[philo->left_fork_num]);
	pthread_mutex_unlock(&info->forks[philo->right_fork_num]);
	return (CONTINUE);
}

int eat(t_philo *philo, t_info *info)
{
	if (g_info.anyone_dead == TRUE)
		return (END);
	if (eat_one_direction(philo, info) == END)
		return (END);
	return (CONTINUE);
}
