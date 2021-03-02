# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>
# include <semaphore.h>
# include <stdio.h>
# include <stdbool.h>


void *philo_do(void *param)
{
	printf("value : %lu\n", (long)param);
	return (NULL);
}

int main()
{
	int count = 5;
	pthread_t array[5];
	int i = 0;
	while (i < count)
	{
		pthread_create(&array[i], NULL, philo_do, (void *)i);
		// pthread_join(array[i], NULL); // 여기다가 넣어주면, 순서대로 철학자 한명씩 먹고자고생각하는게 됨. 나머지는 멍때리는 중
		i++;
	}
	i = 0;
	while (i < count)
	{
		pthread_join(array[i], NULL);
		i++;
	}
	return (1);
}
