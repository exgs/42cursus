#include "philo.h"

void full_list_close_all()
{
	int i = 0;
	while (i < g_philo_num)
	{
		sem_wait(g_info.full_list[i]);
		i++;
	}
}

void *check_full_people(void *param)
{
	t_philo *philos = (t_philo *)param;
	//초기화, 일딴 문 닫고 시작함
	full_list_close_all();
	int i = 0;
	// 0번 부터 탐색을 시작한다는 점이 결국은 0번이 다 먹는 상황이와야, 다음 사람을 탐색한다는 것이 조금 걸리긴 함.
	while (i < g_philo_num)
	{
		sem_wait(g_info.full_list[i]);
		i++;
	}
	kill_all(philos);
	clear_all(philos);
	exit(0);
}


void *process_monitoring(t_philo *philos)
{
	// 철학자들이 모두 배부르게 식사했는지 모니터링함.
	pthread_t full_people;
	pthread_create(&full_people, NULL, check_full_people, philos);
	int i;
	int status = 0;
	// 철학자들이 죽었는지 모니터링함.
	while (1)
	{
		i = 0;
		while (i < g_philo_num)
		{
			if (philos[i].pid == waitpid(philos[i].pid, &status, WNOHANG))
			{
				kill_all(philos); // 자식프로세스 다 죽임
				clear_all(philos);
				exit(0); // 부모프로세스 스스로도 종료
			}
			i++;
		}
		accurate_sleep(5);
	}
	// 무한루프 도느라 여기까지 오지도 못함. 그리고 죽거나, 밥 다 먹거나, 위에서 exit()나옴
	pthread_join(full_people, NULL);
}

int start(t_philo *philos, t_info *info)
{
	int		i;
	int		status;
	pid_t	pid;
	i = 0;
	// 부모는 반복문을 돌면서 자식만 내뱉는 상황. 제곱배수로 자식이 생성되지않게하기위함.
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

	if (-1 == set_info_argv(&g_info, argc, argv))
	{
		printf("error\n");
		return (-1);
	}
	g_info.basetime = get_absolute_time();
	print_info(&g_info);
	g_philo_num = g_info.number_of_philosophers; // 나 편하자고 전역변수 설정
	philos = malloc(sizeof(t_philo) * g_philo_num);
	set_philos(philos, &g_info);
	semaphore_init(&g_info);
	start(philos, &g_info);

	clear_all(philos);
	return (0);
}
