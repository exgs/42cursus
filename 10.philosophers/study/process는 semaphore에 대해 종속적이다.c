#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>

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
	printf("%d\n", sem_unlink("hi"));
	hi = sem_open("hi", O_CREAT ,0, 1);
	if (hi == NULL)
		exit(1);
	int *int_pointer = &g_value;
	int a = 0;
	pid_t pid;
	if ((pid = fork()) == 0)
	{
		sem_wait(hi);
		g_value = 10000;
		print_value("child", int_pointer);
		sleep(3);
		#pragma region 순서가 뒤바뀌면 안됨
		sem_post(hi);
		exit(1);
		#pragma endregion
	}
	else
	{
		usleep(1000); // 자식 부터 실행되도록하면, waitpid가 없어도 됨
		// waitpid(pid, 0, 0);
		sem_wait(hi);
		print_value("parent", int_pointer);
		sem_post(hi);
	}
	sem_close(hi);
	return (0);
}