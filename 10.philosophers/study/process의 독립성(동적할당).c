#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>



int main()
{
	sem_t *sem;
	sem_unlink("/sem");
	sem_open("/sem", O_CREAT | O_EXCL, 0755, 1);
	
	int *g_value = malloc(sizeof(int));
	*g_value = 20;
	int a = 0;
	pid_t pid;
	if ((pid = fork()))
	{
		sem_wait(sem);
		(*g_value)++;
		sem_post(sem);
		printf("child : %d\n", *g_value);
		printf("child g_value: %p\n", g_value);
		exit(1);
	}
	else
	{
		waitpid(pid, NULL, 0);
	}
	printf("----------------------------------------\n");
	printf("parent : %d\n", *g_value);
	printf("parent g_value: %p\n", g_value);

	return (0);
}

// 글로벌 변수라도 영향을 못 미친다.
// 포인터로도 못 넘겨준다.
