#include <stdio.h>
#include <string.h>

int main()
{
	FILE *file;
	char buf[100];
	int temp;
	memset(buf, 0, 100);
	if (NULL == (file = fopen("test", "r")))
	{
		printf("There is no file\n");
		return (1);
	}
	while ((1 == (temp = fread(buf, 1, 1, file))))
	{
		printf("%c", buf[0]);
	}
	// temp = fread(buf, 300, 1, file);
	// printf("temp:%d\n", temp);
	// printf("%s\n", buf);
}