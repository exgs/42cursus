#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *str = malloc(sizeof(char)*50);
	scanf("%s",str);
	printf("%s\n",str);
	free(str);
	return 0;
}