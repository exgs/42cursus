#include "philo.h"

void *test(void *param)	
{
	printf("hello : %d\n", (long)param);
	return (void *)((long)param + 100);
}

int start(t_philo *philos, t_info *info)
{
	int i;

	i = 0;
	while (i < g_philo_num)
	{
		philos[i].when_eat = get_relative_time();
		pthread_create(&philos[i].thread, NULL, philo_do, (void *)&philos[i]);
		// pthread_create(&philos[i].thread, NULL, test, (void *)i); // 테스트 코드
		// pthread_join(philos[i].thread, NULL); // 여기다가 넣어주면, 순서대로 철학자 한명씩 먹고자고생각하는게 됨. 나머지는 멍때리는 중
		i++;
	}
	i = 0;
	while (i < g_philo_num)
		pthread_join(philos[i++].thread, NULL);
}

int main(int argc, char *argv[])
{
	t_philo *philos;

	sem_unlink("/forks");
	sem_unlink("/print_sema");
	sem_unlink("/chosen_people");
	if (-1 == set_info_argv(&g_info, argc, argv))
	{
		printf("error\n");
		return (-1);
	}
	set_info(&g_info);
	print_info(&g_info);
	g_philo_num = g_info.number_of_philosophers; // 나 편하자고 전역변수 설정
	philos = malloc(sizeof(t_philo) * g_philo_num);
	set_philos(philos, &g_info);
	semaphore_init(&g_info);
	start(philos, &g_info);

	free_all(philos);
	sem_close(g_info.forks);
	sem_unlink("/forks");
	sem_close(g_info.print_sema);
	sem_unlink("/print_sema");
	sem_close(g_info.chosen_people);
	sem_unlink("/chosen_people");
	return (0);
}

void free_all(t_philo *philos)
{
	free(philos);
	free(g_info.full_list);
}
