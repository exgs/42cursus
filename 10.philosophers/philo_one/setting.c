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
	return (1);
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
	if (info->meal_full != 0)
		info->full_list = malloc(sizeof(char) * g_philo_num);
	memset(info->full_list, 0, g_philo_num);
	return (1);
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
	return (1);
}

//5개가 넘어가기때문에 삭제해야함
void print_info(t_info *info)
{
	printf("%d\n", info->number_of_philosophers);
	printf("%d\n", info->time_to_die);
	printf("%d\n", info->time_to_eat);
	printf("%d\n", info->time_to_sleep);
	printf("%d\n", info->meal_full);
}