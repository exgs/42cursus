//http://forum.falinux.com/zbxe/index.php?document_srl=413254&mid=C_LIB

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void (*old_fun2)(int);

void old_fun(int signo)
{
	printf("old fun\n");
}

void sigint_handler(int signo)
{
	printf("Ctrl + C 키를 누르셨습니다.\n");
	printf("다시 누르시면 종료됩니다.\n");
	printf("old_fun : %p\n", old_fun);
	printf("old_fun2 :%p\n", old_fun2); //전역변수라서 0인것
	printf("SIG_DFL %d\nSIG_IGN %d\nSIG_ERR %d\n", (int)SIG_DFL, (int)SIG_IGN, (int)SIG_ERR);
	signal(SIGINT, old_fun);
}

int main(void)
{
	old_fun2 = signal(SIGINT, sigint_handler); //signal의 return값 0 or -1
	//https://pubs.opengroup.org/onlinepubs/7908799/xsh/signal.html
	printf("main에서 old_fun2 %d\n", (int)old_fun2);
	while (1)
	{
		printf("하하하\n");
		sleep(1);
	}
}
