#include "philo.h"

void *test(void *param)	
{
	printf("hello : %d\n", (long)param);
	return (void *)((long)param + 100);
}

void *monitoring(void* param)
{
	return (NULL);
}

int print_status(unsigned char status, t_philo *philo, t_info *info)
{
	unsigned long interval;
	interval = get_basetime() - info->basetime;
	pthread_mutex_lock(&info->print_mutex); // 뮤텍스 락을 여기다가 걸어줘야 내가 원하는 만큼만 나온다.
	// if문에 대한 판단에 따른 선고 결과가 적용되기도 전에, if문에 더 들어옴
	if (philo->meal_num != 0 && philo->meal_num > info->number_of_times_each_philosopher_must_eat)
	{
		pthread_mutex_unlock(&info->print_mutex);
		return (1);
	}
	printf("time : %d | philo_num : %d | \n", interval, philo->whoami);
	if(status == EATING)
	{
		philo->meal_num++;
		printf("meal_num : %d\n", philo->meal_num);
		printf("eating\n");
	}
	else if(status == SLEEPING)
	{
		printf("sleeping\n");
	}
	else if(status == THINKING)
	{
		printf("thinking\n");
	}
	pthread_mutex_unlock(&info->print_mutex);
	return (0);
}

//한명의 철학자의 행동을 정의한 함수
void *philo_do(void *temp)
{
	t_philo *philo = ((t_param *)temp)->philo;
	t_info *info = ((t_param *)temp)->info;
	/* monitoring()가 들어가야한다. */
	// pthread_t thread;
	// pthread_create(&thread, NULL, monitoring, temp?)
	while (1)
	{
		if (print_status(EATING, philo, info))
			break ;
		print_status(SLEEPING, philo, info);
		print_status(THINKING, philo, info);
		// eat();
		//sleep
		//thinking
	}
	return (NULL);
}

int start(t_philo *philos, t_info *info)
{
	t_param param;
	mutex_init(info);
	param.info = info;

	int i = 0;
	while (i < g_philo_num)
	{
		param.philo = &philos[i]; //할당한다.
		pthread_create(&philos[i].thread, NULL, philo_do, (void *)&param);
		i++;
	}

	i = 0;
	while (i < g_philo_num)
		pthread_join(philos[i++].thread, NULL);
}

int main(int argc, char *argv[])
{
	t_info info;
	t_philo *philos;

	if (-1 == set_info_argv(&info, argc, argv))
	{
		printf("error\n");
		return (-1);
	}
	set_info(&info);
	g_philo_num = info.number_of_philosophers; // 나 편하자고 전역변수 설정
	philos = malloc(sizeof(t_philo) * g_philo_num);
	set_philos(philos, &info);
	start(philos, &info);
	return (0);
}
