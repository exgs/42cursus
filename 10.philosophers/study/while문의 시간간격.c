# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>
# include <semaphore.h>
# include <stdio.h>
# include <stdbool.h>

int main()
{
	unsigned long u_now;
	struct timeval second;

	int count = 0;
	while (1)
	{
		count++;
		gettimeofday(&second, NULL);
		// now = second.tv_sec * 1000 + second.tv_usec / 1000;
		u_now = second.tv_usec;
		printf("%d : [%lu]\n", count, u_now);
	}
	// 1 microsecond / 1 while
	// 10^6회 / 1 second
	return (1);
}
