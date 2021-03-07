#include "philo.h"
#include <limits.h>

int set_info_argv(t_info *info, int argc, char *argv[])
{
	if (!(argc == 5 || argc == 6))
		return (-1);
	if (2 > (info->number_of_philosophers = ft_atoi(argv[1]))) // 철학자 수
		return (-1);
	if (0 >= (info->time_to_die = ft_atoi(argv[2])))// 철학자의 라이프타임
		return (-1);
	if (0 >= (info->time_to_eat = ft_atoi(argv[3]))) // 먹는데 걸리는 시간
		return (-1);
	if (0 >= (info->time_to_sleep = ft_atoi(argv[4]))) // 자는 시간
		return (-1);
	if (argv[5] != NULL)
	{
		if (0 >= (info->meal_full = ft_atoi(argv[5])))
			return (-1);
	}
	else
		info->meal_full = 0;
	return (1);
}

void semaphore_init(t_info *info)
{
	sem_unlink_all();
	info->forks = sem_open("/forks", O_CREAT | O_EXCL , 0755, g_philo_num);
	info->chosen_people = sem_open("/chosen_people", O_CREAT | O_EXCL , 0755, g_philo_num / 2);
	info->print_sema = sem_open("/print_sema", O_CREAT | O_EXCL , 0755, 1);
	info->anyone_dead = sem_open("/anyone_dead", O_CREAT | O_EXCL , 0755, 1);
	info->full_list = (sem_t **)malloc(sizeof(sem_t *) * g_philo_num);

	char *temp;
	int i = 0;
	while (i < g_philo_num)
	{
		temp = ft_itoa(i);
		info->full_list[i] = sem_open(temp, O_CREAT | O_EXCL, 0755, 1);
		free(temp);
		i++;
	}
}

int set_philos(t_philo *philos, t_info *info)
{
	for (size_t i = 0; i < g_philo_num; i++)
	{
		unsigned long init_time;

		init_time = get_relative_time();
		philos[i].whoami = i;
		philos[i].when_eat = init_time;
		philos[i].meal_num = 0;
	}
}

//함수 다섯개가 넘어가서 나중에 지워야함
void print_info(t_info *info)
{
	printf("%d\n", info->number_of_philosophers);
	printf("%d\n", info->time_to_die);
	printf("%d\n", info->time_to_eat);
	printf("%d\n", info->time_to_sleep);
	printf("%d\n", info->meal_full);
}

void kill_all(t_philo *philos)
{
	int i = 0;
	while (i < g_philo_num)
		kill(philos[i++].pid, SIGKILL);
}
