#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

int main(void)
{
	int fd1; int fd2;
	int d1; int d2;
	char buf[4];
	char message[32] = {"hi\n"};
	fd1 = open("1.txt", O_RDWR|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR);
	fd2 = open("2.txt", O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
	d1 = dup(fd1);
	dup2(d1, STDOUT_FILENO);
	// dup2(fd2, d1);
	printf("h2");
	close(fd1);
	close(fd2);
}
