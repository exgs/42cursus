
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>
# include <semaphore.h>
# include <stdio.h>

int main()
{
	struct timeval mytime;
	printf("start\n");
	int count = 10;
	for (size_t i = 0; i < count; i++)
	{
		gettimeofday(&mytime, NULL);
		printf("%d\n", mytime.tv_sec);
		printf("%d\n", mytime.tv_usec);
		sleep(1); // 최소한 1초는 잔다. 더 잘 수도 있음
	}
	
	printf("start\n");
	return (0);
}
