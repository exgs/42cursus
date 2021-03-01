#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>
# include <semaphore.h>
# include <stdio.h>

pthread_mutex_t mutex; // 어디서나 접근할 수 있게 만들려면 전역변수로 만드는 것이 옳다.


typedef struct s_info
{
	int number_of_philosophers;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int number_of_times_each_philosopher_must_eat;
}	t_info;


typedef struct s_man
{
	pthread_t thread;
	int lifetime;
}	t_man;

#endif
