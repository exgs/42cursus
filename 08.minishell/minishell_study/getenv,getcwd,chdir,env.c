#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *getpwd(char *str)
{
	return (char *)getenv(str);
}

int main(int argc, char **argv, char **env)
{
	int i = 0;
	char buf[255];
	while (env[i] != NULL)
	{
		printf("%d번째는 %s\n", i, env[i]);
		printf("%s : %s\n",argv[i + 2], getpwd(argv[i + 2]));
		i++;
		if (i == 5)
			break;
	}
	printf("----------------------------------\n");
	getcwd(buf, 255);
	printf("%s\n", buf);
	printf("chdir '..'실행\n");
	chdir("..");
	getcwd(buf, 255);
	printf("%s\n", buf);
}