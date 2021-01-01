/* https://www.youtube.com/watch?v=rggw61JtGz0 */

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void killmyself()
{
	exit(EXIT_SUCCESS); // portable codeing style
}
void myhandle(int mysignal)
{
	printf("my handle with signal %d\n", mysignal);
	
	signal(SIGINT, killmyself); //SIGINT에 따른 syscall함수를 변경시킴
}

int main(int argc, char *argv[])
{
	int i = 0;
	signal(SIGINT, myhandle); //SIGINT에 따른 syscall함수를 변경시킴
	while (1)
	{
		printf("i = %d\n", i);
		i++;
		sleep(1); 
	}
	return (0);
}
