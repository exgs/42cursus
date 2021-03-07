#include "philo.h"

void *test(void *param)	
{
	printf("hello : %d\n", (long)param);
	return (void *)((long)param + 100);
}

void kill_all(t_philo *philos)
{
	int i = 0;
	while (i < g_philo_num)
		kill(philos[i++].pid, SIGKILL);
}


void *check_full_people(void *param)
{
	t_philo *philos = (t_philo *)param;
	int i = 0;
	//초기화, 일딴 문 닫고 시작함
	while (i < g_philo_num)
	{
		sem_wait(g_info.full_list[i]);
		i++;
	}
	i = 0;
	while (i < g_philo_num)
	// 0번 부터 탐색을 시작한다는 점이 결국은 0번이 다 먹기를 기다려야 다음 사람을 탐색한다는 것이 조금 걸리긴 함.
	{
		sem_wait(g_info.full_list[i]);
		sem_post(g_info.full_list[i]);
		i++;
	}
	kill_all(philos);
	exit(0);
}


void *process_monitoring(t_philo *philos)
{
	pthread_t full_people;
	
	pthread_create(&full_people, NULL, check_full_people, philos);
	int i;
	int status = 0;
	while (1)
	{
		i = 0;
		while (i < g_philo_num)
		{
			// sem_wait(g_info.anyone_dead);
			if (philos[i].pid == waitpid(philos[i].pid, &status, WNOHANG))
			{
				kill_all(philos); // 자식프로세스 다 죽임
				// sem_post(g_info.anyone_dead);
				exit(0); // 부모프로세스 스스로도 종료
			}
			// sem_post(g_info.anyone_dead);
			i++;
		}
		accurate_sleep(5);
	}
	// 무한루프 도느라 여기까지 오지도 못함.
	pthread_join(full_people, NULL);
}

int start(t_philo *philos, t_info *info)
{
	int		i;
	int		status;
	pid_t	pid;
	i = 0;
	while (i < g_philo_num)
	{
		if ((philos[i].pid = fork()) == 0)
			break;
		i++;
	}
	if (i != g_philo_num)
		philo_do(&philos[i]);
	else
		process_monitoring(philos);
	return (CONTINUE);
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
