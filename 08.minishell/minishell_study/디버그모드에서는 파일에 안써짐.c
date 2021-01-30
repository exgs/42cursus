#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
    pid_t childpid;
    int fds[2];
    int fd = open("./temp", O_RDWR | O_APPEND | O_CREAT, 0755);
	int old_in = dup(STDIN_FILENO);
    int old_out = dup(STDOUT_FILENO);
    if (pipe(fds) != 0)
        return 1;
	childpid = fork();
    if (childpid != 0)
    {
		wait(NULL);
        close(fds[1]);
        dup2(fds[0], STDIN_FILENO);
        dup2(fd, STDOUT_FILENO);
        execlp("grep", "grep", "hello", (char *)0);
		// system("grep hello");
		printf("===\n");
        close(fds[0]);
        close(fd);
        fprintf(stderr, "Failed to execute grep\n");
        return 1;
    }
    else if (childpid == 0)
    {
        const char data[] = "hello how are you\nvery well thanks\n";
        close(fds[0]);
        write(fds[1], data, sizeof(data)-1);
        close(fds[1]);
        return 0;
    }
    else
    {
        fprintf(stderr, "ERROR:\n");
        return 1;
    }
}