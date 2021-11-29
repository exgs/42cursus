
// C program to demonstrate working of Semaphores 
#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 
  
sem_t *semaphore;

  
void* thread(void* arg) 
{ 
	#pragma region critical section
    sem_wait(semaphore); 
    printf("\nEntered..\n"); 
    sleep(2); 
    printf("\nJust Exiting...\n"); 
    sem_post(semaphore); 
	#pragma endregion
} 
  
  
int main() 
{
	if ((semaphore = sem_open("semaphore", O_CREAT, 0, 1)) == NULL)
		perror("what");
    pthread_t t1,t2; 
    pthread_create(&t1,NULL,thread,NULL); 
    pthread_create(&t2,NULL,thread,NULL); 
    pthread_join(t1,NULL); 
    pthread_join(t2,NULL); 
	
    sem_close(semaphore);
	sem_unlink("semaphore");
    return 0; 
} 
