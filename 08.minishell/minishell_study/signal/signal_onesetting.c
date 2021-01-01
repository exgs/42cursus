/*
https://htst.tistory.com/64

-----------------------------------------------------------------------------------------------

함수 사용법                                         함수 사용예                              설명

-----------------------------------------------------------------------------------------------

signal(시그널번호, SIG_DFL)             signal(SIGINT, SIG_DFL)       SIGINT 시그널 실행

signal(시그널번호, SIG_IGN)             signal(SIGQUIT, SIG_IGN)      SIGQUIT 시그널 무시

signal(시그널번호, handler함수)          signal(SIGINT, handler)       SIGINT(CTRL + C)가 입력되면

                                                                     handler() 함수를 실행

------------------------------------------------------------------------------------------------

*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

/* Ctrl + C function */
void sigint_handler(int signo)
{
	printf("sigint_handler received %d\n", signo);
	signal(SIGQUIT, SIG_IGN); /* signal execute */
}

/* Ctrl + Z function */
void sigtstp_handler(int signo)
{
	printf("sigtstp_handler received %d\n", signo);
	signal(SIGQUIT, sigint_handler); /* signal not execute */
}

/* Ctrl + \ function */
void sigquit_handler(int signo)
{
	printf("sigquit_handler received %d\n", signo);
	signal(SIGQUIT, sigtstp_handler); /* signal execute */
}

int main(void)
{
	int i = 1;
	if (signal(SIGQUIT, sigquit_handler) == SIG_ERR)
		printf("\ncan't catch signal\n");
	while(i)
	{
		printf("%d\n", i);
		sleep(1);
		i++;
	}
	return (0);
}