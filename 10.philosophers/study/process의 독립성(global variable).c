#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>


int g_value = 20;

int main()
{
	int *temp = &g_value;
	int a = 0;
	pid_t pid;
	if ((pid = fork()))
	{
		g_value++;
		printf("child : %d\n", g_value);
		printf("child g_value: %p\n", &g_value);
		printf("child : %d\n", *temp);
		printf("child temp: %p\n", temp);
		printf("child &temp: %p\n", &temp);
		exit(1);
	}
	else
	{
		waitpid(pid, NULL, 0);
	}
	printf("----------------------------------------\n");
	printf("parent : %d\n", g_value);
	printf("parent g_value: %p\n", &g_value);
	printf("parent : %d\n", *temp);
	printf("parent temp: %p\n", temp);
	printf("parent &temp: %p\n", &temp);

	return (0);
}

// 글로벌 변수라도 영향을 못 미친다.
// 포인터로도 못 넘겨준다.
