#include "philo.h"

int set_info_argv(t_info *info, int argc, char *argv[])
{
	if (!(argc == 5 || argc == 6))
		return (-1);
	// 음수나 zero 일때, 처리를 해줘야함.
	info->number_of_philosophers = atoi(argv[1]);
	info->time_to_die = atoi(argv[2]);
	info->time_to_eat = atoi(argv[3]);
	info->time_to_sleep = atoi(argv[4]);
	if (argv[5] != NULL)
		info->number_of_times_each_philosopher_must_eat = atoi(argv[5]);
	else
		info->number_of_times_each_philosopher_must_eat = 0;
}

void mutex_fork_init(t_info *info)
{
	int i = 0;
	while (i < g_philo_num)
		pthread_mutex_init(&(info->forks[i++]), NULL);
}

void mutex_init(t_info *info)
{
	mutex_fork_init(info);
	pthread_mutex_init(&info->print_mutex, NULL);
}

int set_info(t_info *info)
{
	info->forks = malloc(sizeof(mutex) * info->number_of_philosophers);
	info->anyone_dead = FALSE;
	info->basetime = get_basetime();
	info->forks = malloc(sizeof(mutex) * info->number_of_philosophers);
}

int set_philos(t_philo *philos, t_info *info)
{
	for (size_t i = 0; i < g_philo_num; i++)
	{
		philos[i].whoami = i;
		philos[i].when_eat = get_basetime();
		philos[i].left_fork_num = philos[i].whoami;
		philos[i].right_fork_num = philos[i].whoami - 1;
		if (philos[i].right_fork_num == -1)
			philos[i].right_fork_num = g_philo_num;
		philos[i].meal_num = 0;
	}
}
