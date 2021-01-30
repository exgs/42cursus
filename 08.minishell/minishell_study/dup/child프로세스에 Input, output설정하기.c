
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

int main(void)
{
	int fd[2], ret;
	int df[2];
	char message[32] = {"hi hello there\n"};
	char message_f[32] = {"lalalalal\n"};

	pipe(fd);
	write(fd[1], message, 32);
	pipe(df);
	ret = fork();
	if (ret == 0)
	{
		char buf[32];
		read(fd[0], buf, 32);
		dup2(df[1],1);
		write(1, buf, 32);
		printf("children\n");
		exit(0);
	}
	else
	{
		char buf2[32];
		wait(NULL);
		printf("parent\n");
		read(df[0], buf2, 32);
		printf("parent:%s\n", buf2);
	}
	
	
	
}