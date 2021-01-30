#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
	int	fdA[2];
	int	fdB[2];
	pipe(fdA);
	pipe(fdB);
	int dup_in = dup(0);
	int dup_out = dup(1);
	if (!fork())
	{
		close(fdA[0]);
		dup2(fdA[1], 1);
		char *str1[3] = {"ls", "-la", 0};
		execve("/bin/ls", str1, NULL);
	}
	else
	{
		close(fdA[1]);
		wait(0);
	}
	dup2(fdA[0], 0);
	if (!fork())
	{
		char *str2[3] = {"wc", 0};
		execve("/usr/bin/wc", str2, NULL);
	}
	else
	{
		wait(0);
	}
	dup2(dup_in, 0); //원상복귀
// 	if (!fork())
// 	{
// //		dup2();
// 		char *str3[3] = {"wc", 0};
// 		execve("/usr/bin/wc", str3, NULL);
// 	}
	close(fdA[0]);
	close(fdA[1]);
	close(fdB[0]);
	close(fdB[1]);
}