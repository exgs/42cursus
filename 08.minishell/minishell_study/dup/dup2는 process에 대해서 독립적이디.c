
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

int main(void)
{
	int fd1, ret;
	int fd2;
	char message[32] = {"hi hello there\n"};
	char message_f[32] = {"lalalalal\n"};

	fd1 = open("text.txt", O_RDWR|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR);
	printf("file open\n");
	dup2(fd1, STDOUT_FILENO);
	ret = fork();
	if (ret == 0)
	{
		printf("children\n");
		exit(0);
	}
	else
	{
		printf("parent\n");
	}

	close(fd1);
}