#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int cnt=0;

void	*th_func(void *name)
{
    int i;
    //======== critical section =============
    int cnt = 0;
	// cnt = 0;
	printf("cnt는 공유자원인가요? : %p\n", &cnt);
    for (i = 0; i < 10000; i++)
    {
        printf("[%s] cnt: %d\n", name, ++cnt);
        usleep(1);
    }
    //========= critical section ============
}

int main()
{
    pthread_t th1,th2;

    pthread_create(&th1, NULL, th_func, (void *)"th1");
    pthread_create(&th2, NULL, th_func, (void *)"th2");

    // pthread_join(th1, NULL);
    // pthread_join(th2, NULL);
	printf("hello world\n");
}
