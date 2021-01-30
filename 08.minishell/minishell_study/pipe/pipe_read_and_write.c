#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
 
#define BUFFER_SIZE 512
int main()
{
    const char *msg[] = {"apple is red", "banana is yellow", "cherry is red"};
    char buffer[BUFFER_SIZE];
    int pipe_fd[2], nRead, i;
	int j;
    pid_t pid;

	printf("fd[0] : %10d | fd[1] : %d\n", pipe_fd[0], pipe_fd[1]);
    pipe(pipe_fd);
	printf("fd[0] : %10d | fd[1] : %d\n", pipe_fd[0], pipe_fd[1]);
    pid = fork();
    // parent process
    if(pid > 0){
        // close input of pipe
        // close(pipe_fd[0]);
        for(i=0; i<3; i++){
            strcpy(buffer, msg[i]);
            write(pipe_fd[1], buffer , BUFFER_SIZE);
        }
		// for(i=0; i<2; i++){
        //     nRead = read(pipe_fd[0], buffer, BUFFER_SIZE);
        //     printf("[parent] %s\n",buffer);
		// }
		close(pipe_fd[0]); //
		close(pipe_fd[1]); // 의미없음
		
		// wait(NULL);
		sleep(3);
    }
    // child process
    else if(pid == 0){
        // //close output of pipe
        // close(pipe_fd[1]);
		printf("---------\n");
        for(i=0; i<3; i++){
            if (0 != (nRead = read(pipe_fd[0], buffer, BUFFER_SIZE)))
            	printf("[child] %s\n",buffer);
			else if (nRead == 0)
				printf("read return 0\n");
		}
	}
	printf("end of main\n");
    return 0;
}