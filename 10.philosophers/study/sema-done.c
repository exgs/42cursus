#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h>

#define THREAD_NUM 5

sem_t *semaphore;
pthread_mutex_t mutex;

void* routine(void* args) {
    sem_wait(semaphore);
    usleep(1000 * 500);
    printf("Hello from thread %d\n", *(int*)args);
    sem_post(semaphore);
    free(args);
}

int main(int argc, char *argv[]) {
    pthread_t th[THREAD_NUM];
	if (semaphore = sem_open("sema", O_CREAT, 0755, 2))
		perror("msg:");
    int i;
    for (i = 0; i < THREAD_NUM; i++) {
        int* a = malloc(sizeof(int));
        *a = i;
        if (pthread_create(&th[i], NULL, routine, a) != 0) {
            perror("Failed to create thread");
        }
    }

    for (i = 0; i < THREAD_NUM; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread");
        }
    }
	exit(0);
    printf("%d\n", sem_close(semaphore));
	printf("%d\n", sem_unlink("sema"));
    return 0;
}
