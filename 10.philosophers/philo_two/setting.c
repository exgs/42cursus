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

void semaphore_fork_init(t_info *info)
{
	if (SEM_FAILED == (info->forks = 
				sem_open("/forks", O_CREAT | O_EXCL, 0755, g_philo_num/2)))
	{
		perror("semaphore_fork_init : ");
		sem_unlink("/forks");
		info->forks = sem_open("/forks", O_CREAT | O_EXCL, 0755, g_philo_num/2);
		// printf("1\n");
		// exit(1);
	}
}

void semaphore_chosen_people_init(t_info *info)
{
	if (SEM_FAILED == (info->chosen_people = 
				sem_open("/chosen_people", O_CREAT | O_EXCL, 0755, g_philo_num/2)))
	{
		perror("chosen people : ");

		sem_unlink("/chosen_people");
		info->chosen_people = sem_open("/chosen_people", O_CREAT | O_EXCL, 0755, g_philo_num/2);
	}
}

void semaphore_init(t_info *info)
{
	semaphore_fork_init(info);
	semaphore_chosen_people_init(info);
	if (SEM_FAILED == (info->print_sema = sem_open("/print_sema", O_CREAT | O_EXCL, 0755, 1)))
	{
		perror("semaphore_init : ");
		sem_unlink("/print_sema");
		info->print_sema = sem_open("/print_sema", O_CREAT | O_EXCL, 0755, 1);
	}
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

static int	atoi_while(const char *str, int i, int sign)
{
	unsigned long long int	sum;

	sum = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		sum *= 10;
		sum += str[i] - 48;
		i++;
	}
	if (sum > LLONG_MAX  && sign == -1) 
		return (0);
	if (sum > LLONG_MAX && sign == 1)
		return (-1);
	return ((int)sum);
}

int			ft_atoi(const char *str)
{
	int i;
	int sign;

	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)) //space and whitespace 건너뛰기
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (!(str[i] >= 48 && str[i] <= 57))
		return (0);
	return (sign * atoi_while(str, i, sign));
}
