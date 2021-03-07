#include "philo.h"

int print_doing(t_status status, t_philo *philo)
{
	if (status == EATING)
	{
		printf("is eating\n");
		philo->meal_num++;
		// 87, 88번째 줄에 둘까?
		// if (g_info.meal_full != 0 && g_info.meal_full <= philo->meal_num)
		// 	sem_post(g_info.full_list[philo->whoami]);
	}
	else if(status == SLEEPING)
	{
		printf("is sleeping\n");
	}
	else if(status == THINKING)
		printf("is thinking\n");
	else if(status == RIGHT_TAKEN)
		printf("has taken a right fork\n");
	else if(status == LEFT_TAKEN)
		printf("has taken a left fork\n");
	else if(status == TAKEN)
		printf("has taken a fork\n");
	else if(status == DEAD)
	{
		printf("is dead\n");
		exit(0);
		return (END);
	}
	return (CONTINUE);
}

int doing(t_status status, t_philo *philo, unsigned long interval)
{
	int ret;
	// printf("end?\n");
	sem_wait(g_info.print_sema); // 뮤텍스 락을 여기다가 걸어줘야 내가 원하는 만큼만 나온다.
	// 그러지 않으면, if문에 대한 판단에 따른 선고 결과가 적용되기도 전에, if문에 더 들어옴
	// sem_wait(g_info.anyone_dead);
	// if (g_info.anyone_dead == TRUE)
	// {
		// sem_post(g_info.print_sema);
		// sem_post(g_info.anyone_dead);
	// 	exit(0);
	// 	return (END);
	// }
	printf("[%lu] %d번째 철학자 : ", interval, philo->whoami + 1);
	ret = print_doing(status, philo);
	sem_post(g_info.print_sema);
	// sem_post(g_info.anyone_dead);
	if (ret == CONTINUE)
		return (CONTINUE);
	if (ret == END)
		return (END);
}


void *thread_monitoring(void *param)
{
	t_philo *philo = (t_philo *)param;
	unsigned long time;
	while (1)
	{
		/*모니터링이라서 뮤텍스를 사용하면 안됨. 계속 판단해야돼*/
		// 아래 if문은 필요 없어짐. 그 이유 두가지
		// 1. g_info.anyone_dead가 int가 아니라 (sem_t *)으로 변경.
		// 2. print_doing 함수에서 "is_dead" 출력하고 바로 죽는다. exit()의 강점일까?
		// if (g_info.anyone_dead == TRUE) 
		// 	break;
	
		// 지금 모니터링하고 있는 철학자가 배부르게 먹었을 때는 쓰레드 종료
		// 9,10 번째 두는 게 나을 까 여기다 두는게 나을까? semaphore 안과 밖
		if (g_info.meal_full != 0 && g_info.meal_full <= philo->meal_num)
			sem_post(g_info.full_list[philo->whoami]); // 배부르다고 시그널을 던짐.(최적화를 위해 flag처리도 생각해봄직함)
		// 철학자가 굶어 죽는 상황인지 계산
		time = get_relative_time();
		if (time - philo->when_eat > g_info.time_to_die)
		{
			doing(DEAD, philo, time); // 그래서 시간은 건네줘야함
			// exit(0); 출력하고 죽어야하니깐 이 위치는 아님.
			break;
		}
		accurate_sleep(5);
	}
}

//한명의 철학자의 행동을 정의한 함수
void *philo_do(void *param)
{
	t_philo *philo = (t_philo *)param;
	/* thread_monitoring()가 들어가야한다. */
	pthread_t thread;
	pthread_create(&thread, NULL, thread_monitoring, philo);
	// 공유자원이 프로세스끼리는 공유하기힘듦. 여기서는 세마포어를 이용하는 편법을 이용하자
	if (philo->whoami % 2 == 0)
		accurate_sleep(1);
	while (1)
	{
		if (eat(philo, &g_info) == END)
			break;
		if (doing(SLEEPING, philo, get_relative_time()) == END)
			break ;
		spend_time_of(SLEEPING);
		if (doing(THINKING, philo, get_relative_time()) == END)
			break;
	}
	pthread_join(thread, NULL);
	return (NULL);
}

int eat(t_philo *philo, t_info *info)
{
	sem_wait(info->chosen_people);
	sem_wait(info->forks);
	// 철학자는 자식프로세스이기때문에 exit()으로 끝나서, philo_one, philo_two
	//와 달리 return이 필요없음.
	doing(TAKEN, philo, get_relative_time());
	sem_wait(info->forks);
	doing(TAKEN, philo, get_relative_time());
	doing(EATING, philo, get_relative_time());
	philo->when_eat = get_relative_time();
	spend_time_of(EATING);
	sem_post_all(info);
	return (CONTINUE);
}

void sem_post_all(t_info *info)
{
	sem_post(info->forks);
	sem_post(info->forks);
	sem_post(info->chosen_people);
}
