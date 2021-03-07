#include "philo.h"

void clear_all(t_philo *philos)
{
	free_all(philos);
	sem_clear_all();
}

void free_all(t_philo *philos)
{
	free(philos);
	free(g_info.full_list);
}

void sem_clear_all()
{
	sem_close_all();
	sem_unlink_all();
}

void sem_close_all()
{
	sem_close(g_info.forks);
	sem_close(g_info.print_sema);
	sem_close(g_info.chosen_people);
	sem_close(g_info.anyone_dead);
	// close를 하면, 완전 이상해짐. 그리고 포인터의 주소값이 1,2,3,4 이런식임.
	// 그래서 써주지 않으려함.
	// int i = 0;
	// while (i < g_philo_num)
	// {
	// 	printf("%p\n", g_info.full_list[i]);
	// 	sem_close(g_info.full_list[i]);
	// 	i++;
	// }
}

void sem_unlink_all()
{
	sem_unlink("/chosen_people");
	sem_unlink("/forks");
	sem_unlink("/print_sema");
	sem_unlink("/anyone_dead");
	char *temp;
	int i = 0;
	while (i < g_philo_num)
	{
		temp = ft_itoa(i);
		sem_unlink(temp);
		free(temp);
		i++;
	}
}
