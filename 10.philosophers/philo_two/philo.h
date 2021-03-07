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


# define FALSE 0
# define TRUE 1
# define END 0
# define CONTINUE 1


typedef enum
{
	EATING = 0,
	SLEEPING,
	THINKING,
	TAKEN,
	LEFT_TAKEN,
	RIGHT_TAKEN,
	DEAD
}	t_status;

typedef struct s_info
{
	int number_of_philosophers;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int meal_full;
	unsigned long basetime;
	bool anyone_dead;
	char *full_list;
	sem_t *forks;
	sem_t *chosen_people;
	sem_t *print_sema;
}				t_info;


typedef struct s_philo
{
	pthread_t thread;
	int whoami;
	unsigned long when_eat;
	int meal_num;
}	t_philo;

int g_philo_num;
t_info g_info; // 전역변수로 처리한 이유는 pthread_create가 변수를 하나밖에 넘겨주지 못하기 때문.
// 게다가 쓰레드라서 프로세스처럼 독립적인 메모리가 아니다.

//main.c
int start(t_philo *philos, t_info *info);
int main(int argc, char *argv[]);
void *test(void *param);

//setting.c
int set_info_argv(t_info *info, int argc, char *argv[]);
void semaphore_fork_init(t_info *info);
void semaphore_chosen_people_init(t_info *info);
void semaphore_init(t_info *info);
int set_info(t_info *info);
int set_philos(t_philo *philos, t_info *info);
void print_info(t_info *info);
int			ft_atoi(const char *str);

//time.c
unsigned long get_relative_time();
unsigned long get_absolute_time();
int spend_time_of(t_status doing);
void accurate_sleep(unsigned long milisecond);

//do.c
int print_doing(t_status status, t_philo *philo);
int doing(t_status status, t_philo *philo, unsigned long interval);
bool is_all_philos_full();
void *monitoring(void *param);
void *philo_do(void *param);
int eat(t_philo *philo, t_info *info);
void sem_post_all(t_info *info);

//clear.c
void clear_all(t_philo *philos);
void free_all(t_philo *philos);
void sem_clear_all();
void sem_close_all();
void sem_unlink_all();
#endif

