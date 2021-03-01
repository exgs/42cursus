#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t mutex;
int cnt=0;

void	*th_func(void *name)
{
    int i;

    //======== critical section =============
	pthread_mutex_lock(&mutex);
    cnt=0;
    for (i = 0; i <5; i++)
    {
        printf("[%s] cnt: %d\n", name, ++cnt);
        usleep(1);
    }
    //========= critical section ============
	 pthread_mutex_unlock(&mutex);
}

int main()
{
    pthread_t th1,th2;

	// 이 위치여야만 원하는대로 동작하는데, 이유가?
	// phtread가 생성되기전에. mutex를 동적으로 초기화 해준다...
	pthread_mutex_init(&mutex, NULL);

    pthread_create(&th1, NULL, th_func, (void *)"th1");
    pthread_create(&th2, NULL, th_func, (void *)"th2");

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

	pthread_mutex_destroy(&mutex);
}
