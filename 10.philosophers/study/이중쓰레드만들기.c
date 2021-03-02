# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>
# include <semaphore.h>
# include <stdio.h>
# include <stdbool.h>


void *test2(void *param)
{
	printf("test2 : %d\n", (int)param);
}

void *test(void *param)
{
	printf("value : %lu\n", (long)param);
	pthread_t pid2;
	pthread_create(&pid2, NULL, test2, (void *)param);
	pthread_join(pid2, NULL);
	return (NULL);
}

int main()
{
	int count = 5;
	pthread_t array[5];
	int i = 0;
	while (i < count)
	{
		pthread_create(&array[i], NULL, test, (void *)i);
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
