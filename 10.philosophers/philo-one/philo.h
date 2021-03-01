#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>
# include <semaphore.h>
# include <stdio.h>
# include <stdbool.h>

pthread_mutex_t mutex; // 어디서나 접근할 수 있게 만들려면 전역변수로 만드는 것이 옳다.
int g_philo_num;

# define FALSE 0
# define TRUE 1


enum
{
	EATING = 0,
	SLEEPING,
	THINKING
};

typedef struct s_info
{
	int number_of_philosophers;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int number_of_times_each_philosopher_must_eat;
	unsigned long basetime;
	bool anyone_dead;
	pthread_mutex_t *forks;
	pthread_mutex_t print_mutex;
}				t_info;


typedef struct s_philo
{
	pthread_t thread;
	int whoami;
	int when_eat;
	int left_fork_num;
	int right_fork_num;
	int meal_num;
	// unsigned char status;
}	t_philo;

typedef struct s_param
{
	t_info *info;
	t_philo *philo;
}				t_param;

// philo-one.c


// philo-one-utils.c
unsigned long get_basetime();
void print_info(t_info *info);
int set_info_argv(t_info *info, int argc, char *argv[]);

// philo-init-exit.c
void mutex_fork_init(t_info *info);
void mutex_init(t_info *info);
int set_info(t_info *info);
int set_philos(t_philo *philos, t_info *info);
#endif
