#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

/* this function is run by the second thread */
void *inc_x(void *x_void_ptr)
{
	int *x_ptr = (int *)x_void_ptr;
	while(++(*x_ptr) < 100);

	printf("x increment finished\n");
	/* the function must return something - NULL will do */
	return NULL;
}

int main()
{
	int x = 0, y = 0;
	printf("x: %d, y: %d\n", x, y);

	pthread_t inc_x_thread;
	if(pthread_create(&inc_x_thread, NULL, inc_x, &x))
	{
		fprintf(stderr, "Error creating thread\n");
		return 1;
	}

	#pragma region 1. 비동기의 동기화: sleep
	sleep(1);
	#pragma endregion

	while(++y < 100);
	printf("y increment finished\n");

	#pragma region 2. 비동기의 동기화: 종료시 event 발생
	if(pthread_join(inc_x_thread, NULL))
	{
		fprintf(stderr, "Error joining thread\n");
		return 2;
	}
	#pragma endregion

	/* show the results - x is now 100 thanks to the second thread */
	printf("x: %d, y: %d\n", x, y);
	return 0;
}
