#include "philo.h"

int set_info_argv(t_info *info, int argc, char *argv[])
{
	if (!(argc == 5 || argc == 6))
		return (-1);
	// 음수나 zero 일때, 처리를 해줘야함.
	info->number_of_philosophers = atoi(argv[1]); // 철학자 수
	info->time_to_die = atoi(argv[2]); // 철학자의 라이프타임
	info->time_to_eat = atoi(argv[3]); // 먹는데 걸리는 시간
	info->time_to_sleep = atoi(argv[4]); // 자는 시간
	if (argv[5] != NULL)
		info->meal_full = atoi(argv[5]); // 이정도 묵었으면 마이 묵었다.
	else
		info->meal_full = 0;
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
	info->forks = malloc(sizeof(pthread_mutex_t) * info->number_of_philosophers);
	info->anyone_dead = FALSE;
	info->basetime = get_absolute_time();
}

int set_philos(t_philo *philos, t_info *info)
{
	for (size_t i = 0; i < g_philo_num; i++)
	{
		unsigned long init_time;

		init_time = get_relative_time();
		philos[i].whoami = i;
		philos[i].when_eat = init_time;
		philos[i].left_fork_num = philos[i].whoami;
		philos[i].right_fork_num = philos[i].whoami - 1;
		if (philos[i].right_fork_num == -1)
			philos[i].right_fork_num = g_philo_num - 1;
		philos[i].meal_num = 0;
	}
}

unsigned long get_absolute_time()
{
	struct timeval time;
	unsigned long milisecond;
	gettimeofday(&time, NULL);
	milisecond = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (milisecond);
}

unsigned long get_relative_time()
{
	struct timeval time;
	unsigned long milisecond;
	unsigned long relative_milisecond;
	gettimeofday(&time, NULL);
	milisecond = time.tv_sec * 1000 + time.tv_usec / 1000;
	relative_milisecond = milisecond - g_info.basetime;
	return (relative_milisecond);
}

void print_info(t_info *info)
{
	printf("%d\n", info->number_of_philosophers);
	printf("%d\n", info->time_to_die);
	printf("%d\n", info->time_to_eat);
	printf("%d\n", info->time_to_sleep);
	printf("%d\n", info->meal_full);
}
