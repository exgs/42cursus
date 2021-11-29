// Using Semaphore
 
#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
 
sem_t *semaphore;
int num;

void *threadFunc(void *arg)
{
	char *threadName = (char *)arg;
	int i;
	if(num != 0)
	{
		sem_wait(semaphore);
		num--;
		printf("%s 이 화장실을 이용하기 시작합니다.\n", threadName);
 
        // 화장실 이용하는 시간이라 가정
        // for(i = 0 ; i < 1000000 ; i++){}
		sleep(1);
		printf("%s 이 화장실 이용을 마쳤습니다.\n", threadName);
        num++;
        sem_post(semaphore);
    }
    else if (num == 0)
    {
        printf("화장실이 꽉 차 %s 이 기다리고 있습니다.\n", threadName);
		sem_wait(semaphore);
		sleep(1);
        // while(num == 0){}
        printf("%s 이 화장실 이용을 하고 마쳤습니다.\n", threadName);
        num++;
        sem_post(semaphore);
    }
        
    
    return NULL;
}
 
 
int main()
{
	num = 1;
    pthread_t thread1, thread2, thread3;
 
	if ((semaphore = sem_open("semaphore", O_CREAT, 0, num)) == NULL)
		perror("msg:");

 
    printf("Semaphore test Start!\n");
    // 스레드 생성
    pthread_create(&thread1, NULL, threadFunc, "thread1");
    pthread_create(&thread2, NULL, threadFunc, "thread2");
    pthread_create(&thread3, NULL, threadFunc, "thread3");
 
    // 스레드 조인
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
 
    printf("모든 스레드가 화장실 이용을 끝냈습니다.\n");
 
    // 세마포어 객체 소멸
    sem_close(semaphore);
	sem_unlink("semaphore");
	
    return 0;
}
