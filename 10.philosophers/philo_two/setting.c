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

void semaphore_fork_init(t_info *info)
{
	if (0 == (info->forks = 
				sem_open("forks", O_CREAT, 0755, g_philo_num / 2)))
		exit(1);
}

void semaphore_init(t_info *info)
{
	semaphore_fork_init(info);
	if (0 == (info->print_sema = sem_open("print_sema", O_CREAT, 0755, 1)))
		exit(1);
}

int set_info(t_info *info)
{
	info->anyone_dead = FALSE;
	info->basetime = get_absolute_time();
	if (info->meal_full != 0)
		info->full_list = malloc(sizeof(char) * g_philo_num);
	memset(info->full_list, 0, g_philo_num);
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
