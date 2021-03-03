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

void *test(void *param)
{
	while (1)
	{
	}
	return (NULL);
}

int main()
{
	int count = 5;
	pthread_t array[5];
	int i = 0;
	while (i < count)
	{
		if (i == 3)
		{
			pthread_create(&array[i], NULL, test, (void *)i);
			i++;
			continue;
		}
		pthread_create(&array[i], NULL, philo_do, (void *)i);
		i++;
	}
	i = 0;
	while (i < count)
	{
		pthread_join(array[i], NULL); // 프로세스가 쓰레드를 기다리는 느낌
		i++;
	}
	printf("end\n");
	return (1);
}
