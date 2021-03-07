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
}

void sem_unlink_all()
{
	sem_unlink("/forks");
	sem_unlink("/print_sema");
	sem_unlink("/chosen_people");
}
