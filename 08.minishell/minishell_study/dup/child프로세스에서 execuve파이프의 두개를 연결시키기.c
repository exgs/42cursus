
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
	dup2(fd[1], df[1]);
	ret = fork();
	if (ret == 0)
	{
		char buf[32];
		read(fd[0], buf, 32);
		dup2(df[1],1);
		// df에 쓰지만, df는 위에서 부모프로세스에서 fd에 연결되도록(dup2) 했기 때문에 연결할 수 있지 않을까?
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
	printf("main\n");
	char buf3[32];
	read(fd[0], buf3, 32);
	printf("main:%s\n", buf3);
}