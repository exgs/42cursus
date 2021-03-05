#include "philo.h"

void accurate_sleep(unsigned long milisecond)
{
	// int i = 0;
	// while (i < 10)
	// {
	// 	usleep(milisecond * 100);
	// 	i++;
	// }
	unsigned long	base;
	unsigned long	cur;

	base = get_absolute_time();
	while (1)
	{
		cur = get_absolute_time();
		if (milisecond < cur - base)
			return ;
		usleep(100);
	}
}

int spend_time_of(t_status doing)
{
	unsigned long milisecond;

	if (doing == EATING)
		milisecond = g_info.time_to_eat;
	if (doing == SLEEPING)
		milisecond = g_info.time_to_sleep;
	accurate_sleep(milisecond);
	// usleep(milisecond * 1000);
}

unsigned long get_absolute_time()
{
	struct timeval time;
	unsigned long milisecond;
	gettimeofday(&time, NULL);
	milisecond = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (milisecond);
}

unsigned long get_relative_time()
{
	struct timeval time;
	unsigned long milisecond;
	unsigned long relative_milisecond;
	gettimeofday(&time, NULL);
	milisecond = time.tv_sec * 1000 + time.tv_usec / 1000;
	relative_milisecond = milisecond - g_info.basetime;
	return (relative_milisecond);
}