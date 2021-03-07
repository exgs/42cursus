#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>

int g_value = 20;
sem_t *hi;

void print_value(char *str, int *temp)
{
	printf("----------------------------------------\n");
	printf("%s : %d\n", str, g_value);
	printf("%s g_value: %p\n", str, &g_value);
	printf("%s : %d\n", str, *temp);
	printf("%s temp: %p\n", str, temp);
	printf("%s &temp: %p\n", str, &temp);
}

int main()
{
	sem_unlink("hi");
	hi = sem_open("/hi", O_CREAT , 0755, 1);
	int *temp = &g_value;
	int a = 0;
	pid_t pid;
	if ((pid = fork()))
	{
		sleep(3);
		g_value++;
		// sem_post(hi);
		sem_wait(hi);
		// sleep(2);
		print_value("child", temp);
		sem_post(hi);
		exit(1);
	}
	else
	{
		sem_wait(hi);// sem_wait(hi);
		waitpid(pid, 0, 0);
		print_value("parent", temp);
		// sem_post(hi);
	}
	sem_close(hi);
	return (0);
}

// 세마포어도 프로세스를 넘어다니지는 못함. 프로세스안에 있는 쓰레드를 관리하는 도구인듯
