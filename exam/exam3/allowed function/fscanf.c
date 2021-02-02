#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	FILE *file;
	float a,b,c = 0;
	int temp;
	char d,f = 0;
	if (NULL == (file = fopen("scanf", "r")))
	{
		printf("no file\n");
		return (1);
	}

	temp =fscanf(file, "%c %f %f %f %c\n", &d, &a, &b, &c, &f);
	printf("temp:%d\n", temp);
	printf("%c %f %f %f %c\n", d, a, b, c, f);
	printf("-----------------\n");
	temp =fscanf(file, "%c %f %f %f %c\n", &d, &a, &b, &c, &f);
	printf("temp:%d\n", temp);
	printf("%c %f %f %f %c\n", d, a, b, c, f);
	temp =fscanf(file, "%c %f %f %f %c\n", &d, &a, &b, &c, &f);
	printf("temp:%d\n", temp);
	printf("%c %f %f %f %c\n", d, a, b, c, f);
	temp =fscanf(file, "%c %f %f %f %c\n", &d, &a, &b, &c, &f);
	printf("temp:%d\n", temp);
	printf("%c %f %f %f %c\n", d, a, b, c, f);
	temp =fscanf(file, "%c %f %f %f %c\n", &d, &a, &b, &c, &f);
	printf("temp:%d\n", temp);
	printf("%c %f %f %f %c\n", d, a, b, c, f);
	temp =fscanf(file, "%c %f %f %f %c\n", &d, &a, &b, &c, &f);
	printf("temp:%d\n", temp);
	printf("%c %f %f %f %c\n", d, a, b, c, f);
	temp =fscanf(file, "%c %f %f %f %c\n", &d, &a, &b, &c, &f);
	printf("temp:%d\n", temp);
	printf("%c %f %f %f %c\n", d, a, b, c, f);
	temp =fscanf(file, "%c %f %f %f %c\n", &d, &a, &b, &c, &f);
	printf("temp:%d\n", temp);
	printf("%c %f %f %f %c\n", d, a, b, c, f);
	temp =fscanf(file, "%c %f %f %f %c\n", &d, &a, &b, &c, &f);
	printf("temp:%d\n", temp);
	printf("%c %f %f %f %c\n", d, a, b, c, f);
	fclose(file);
}