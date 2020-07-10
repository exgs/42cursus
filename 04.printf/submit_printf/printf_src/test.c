#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

struct s_fuck
{
	int num;
	int num2;
};

int main()
{
	struct s_fuck fuck;
	fuck.num = 2;
	fuck.num2 = -1;
	struct s_fuck hell;
	hell = fuck;
	struct s_fuck heaven;
	memcpy(&heaven, &hell, sizeof(hell));
	printf("%d +++ %d\n",fuck.num,fuck.num2);
	printf("%d +++ %d\n",hell.num,hell.num2);
	printf("%d +++ %d\n",heaven.num,heaven.num2);
	{
		/* data */
	};
	
	// char * str = "what the";
	char c = 'A';
	// write(1, &c, 1);
	int i = 48;
	int a ;
	char *memory1 = &c;
	int *memory2 = &a;
	double f = 3/14;
	printf("memory 1 : %p %x %X\n", memory1, memory1, memory1);
	printf("memory 1 : d : %d\n", (int)memory1);
	printf("---\n");
	printf("memory 2 : %p %x %X\n", memory2, memory2, memory2);
	printf("---\n");
	printf("memory 1 : d : %d\n", (int)&f);
	printf("memory 1 : p : %p\n", &f);
	// write(1, &str, 1);
	printf("0---0\n");
	// write(1, str, 4);

	a = i++;
	
	printf("%c\n",'\0');
	printf("-----------------------\n");
	// printf("char %d\n", _INTSIZEOF(char));
	// printf("char %d\n", _INTSIZEOF(char));
	int temp;
	unsigned temp2;
	temp = -2147483648;
	temp2 = temp;
	printf("temp %%d = %d , temp2 %%d = %d\n", temp, temp2);
	printf("temp %%i = %i , temp2 %%i = %i\n", temp, temp2);
	printf("temp %%u = %u , temp2 %%u = %u\n", temp, temp2);
	
	printf("temp %%d = %d \n", -2147483648);
	printf("temp %%i = %i \n", -2147483648);
	printf("temp %%i = %i \n", -2147483648);
	
	printf("--------Catha error case---------------\n");
	printf("temp %%u = %u \n", -1);
	printf("temp %%d = %d \n", 4294967295);
	printf("temp %%d = %d \n", 4294967296);
	return (0);
}