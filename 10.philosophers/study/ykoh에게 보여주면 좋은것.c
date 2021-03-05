// Using Semaphore
 
#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
 
sem_t *semaphore;
 
int num;
 
void *threadF1(void *arg)
{
    int i;
    if(num != 0)
    {
        num--; 
		// 공유자원(전역변수 num)은 num는 1->0이 되었는데, sem_wait가 실행되기 이전에, 다른 쓰레드에서 num = 0 에 대한 동작을 함.
        sem_wait(semaphore);
        printf("스레드 1이 화장실을 이용하기 시작합니다.\n");
 
        // 화장실 이용하는 시간이라 가정
        // for(i = 0 ; i < 1000000 ; i++){}
		sleep(1);
 
        printf("스레드 1이 화장실 이용을 마쳤습니다.\n");
        num++;
        sem_post(semaphore);
    }
    
    else if(num == 0)
    {
        printf("화장실이 꽉 차 스레드 1이 기다리고 있습니다.\n");
        
        while(num == 0){}
        
        printf("스레드 1이 화장실 이용을 하고 마쳤습니다.\n");
        num++;
        sem_post(semaphore);
    }
    
    return NULL;
}
 
void *threadF2(void *arg)
{
    int i;
    if(num != 0)
    {
        num--;
        printf("스레드 2가 화장실을 이용하기 시작합니다.\n");
        sem_wait(semaphore);
 
        // 화장실 이용하는 시간이라 가정
        // for(i = 0 ; i < 1000000 ; i++){}
		sleep(1);
 
        printf("스레드 2가 화장실 이용을 마쳤습니다.\n");
        num++;
        sem_post(semaphore);
    }
    
    else if(num == 0)
    {
        printf("화장실이 꽉 차 스레드 2가 기다리고 있습니다.\n");
        while(num == 0){}
 
        printf("스레드 2가 화장실 이용을 하고 마쳤습니다.\n");
        num++;
        sem_post(semaphore);
    }
        
    
    return NULL;
}
 
void *threadF3(void *arg)
{
    int i;
    if(num != 0)
    {
        num--;
        sem_wait(semaphore);
        printf("스레드 3이 화장실을 이용하기 시작합니다.\n");
 
        // 화장실 이용하는 시간이라 가정
        // for(i = 0 ; i < 1000000 ; i++){}
		sleep(1);
 
        printf("스레드 3이 화장실 이용을 마쳤습니다.\n");
        num++;
        sem_post(semaphore);
    }
    
    else if(num == 0)
    {
        printf("화장실이 꽉 차 스레드 3이 기다리고 있습니다.\n");
        while(num == 0){}
 
        printf("스레드 3이 화장실 이용을 하고 마쳤습니다.\n");
        sem_post(semaphore);
        num++;
    }
        
    
    return NULL;
}
 
int main()
{
	num = 1;
    pthread_t thread1, thread2, thread3;
 
	if (semaphore = sem_open("semaphore", O_CREAT, 0, num))
		perror("msg:");

 
    printf("Semaphore test Start!\n");
    // 스레드 생성
    pthread_create(&thread1, NULL, threadF1, NULL);
    pthread_create(&thread2, NULL, threadF2, NULL);
    pthread_create(&thread3, NULL, threadF3, NULL);
 
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
