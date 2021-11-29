#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>

int g_value = 20;

int main()
{
	int *temp = &g_value;
	int a = 0;
	pid_t pid;
	int *heap_value = malloc(sizeof(int));
	*heap_value = 9;
	if ((pid = fork()))
	{
		g_value = 10000;
		*heap_value = 90000;
		printf("child : %d\n", g_value);
		printf("child g_value: %p\n", &g_value);
		printf("child *heap_value: %d\n", *heap_value);
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
	printf("parent *heap_value: %d\n", *heap_value);
	printf("parent : %d\n", *temp);
	printf("parent temp: %p\n", temp);
	printf("parent &temp: %p\n", &temp);

	return (0);
}

// 전역변수, 힙영역도 서로 다르다.
// 주소값이 같아도 서로 다른 값을 참조하고 있음.
