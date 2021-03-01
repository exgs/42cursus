#include "philo.h"


int get_argv(t_info *info, int argc, char *argv[])
{
	if (!(argc == 5 || argc == 6))
		return (-1);
	info->number_of_philosophers = atoi(argv[1]);
	info->time_to_die = atoi(argv[2]);
	info->time_to_eat = atoi(argv[3]);
	info->time_to_sleep = atoi(argv[4]);
	if (argv[5] != NULL)
		info->number_of_times_each_philosopher_must_eat = atoi(argv[5]);
	else
		info->number_of_times_each_philosopher_must_eat = 0;
}

void print_info(t_info *info)
{
	printf("%d\n", info->number_of_philosophers);
	printf("%d\n", info->time_to_die);
	printf("%d\n", info->time_to_eat);
	printf("%d\n", info->time_to_sleep);
	printf("%d\n", info->number_of_times_each_philosopher_must_eat);
}


void *test(void *param)
{
	printf("hello : %d\n", (long)param);
	return (void *)((long)param + 100);
}

int start(t_info *info, t_man *mans)
{
	
	for (size_t i = 0; i < info->number_of_philosophers; i++)
	{
		pthread_create(&mans[i].thread, NULL, test, (void *)i);
		// printf("%d\n", mans->lifetime);
	}

	void *get_value;
	for (size_t i = 0; i < info->number_of_philosophers; i++)
	{
		pthread_join(mans[i].thread, &get_value);
		printf("get_value : %ld\n", (long)get_value);
	}
}


int main(int argc, char *argv[])
{
	t_info info;
	if (-1 == get_argv(&info, argc, argv))
	{
		printf("error\n");
		return (-1);
	}
	
	t_man *mans;
	mans = malloc(sizeof(pthread_t) * info.number_of_philosophers);
	int i = 0;
	while (i < info.number_of_philosophers)
	{
		mans[i].lifetime = info.time_to_die;
		i++;
	}
	

	// print_info(&info);
	start(&info, mans);
	return (0);
}
