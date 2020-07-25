#include <stdio.h>
#include <stdarg.h>

void printfNumbers_array(int count, ...)
{
	va_list ap;
	int num;
	va_start(ap, count);

	for (int i = 0; i < count; i++)
	{
		num = va_arg(ap, int);
		printf("%d ",num);
	}
	va_end(ap);
	printf("\n");
}

void printfNumbers_string(char *types, ...)
{
	va_list ap;
	char *str = "Hello";
	int i = 0;
	
	va_start(ap, str);//'\0'까지 복사해주네(read함수랑 다르게)
	while (types[i] != '\0')
	{
		switch (types[i])
		{
			case 'i':
				printf("%d ",va_arg(ap, int));
				break;
			case 'd':
				printf("%f ",va_arg(ap, double));
				break;
			case 'c':
				printf("%c ",va_arg(ap, int)); // int 와 double만 자료형으로 사용가능!
				break;
			case 's':
				printf("%s ",va_arg(ap, char *));//4byte?
				break;
			default:
				break;
		}
		i++;
	}
	va_end(ap);
	printf("\n");
}
double average(int count, ...) {
    va_list ap;
    int j;
    double sum = 0;

    va_start(ap, count); /* Requires the last fixed parameter (to get the address) */
    for (j = 0; j < count; j++) {
        sum += va_arg(ap, int); /* Increments ap to the next argument. */
    }
    va_end(ap);

    return sum / count;
}


int main()
{
	printfNumbers_array(1,30,2);
	printfNumbers_array(2,30,40);
	printfNumbers_array(3,3,5,4);
	printfNumbers_array(4,5,3,5,111);
	printfNumbers_string("---------------\n");
	// printfNumbers_string("i", 10);                                       // 정수
    printfNumbers_string("ci", 'a', 10);                                 // 문자, 정수
    printfNumbers_string("dci", 1.234567, 'a', 10);                      // 실수, 문자, 정수
    printfNumbers_string("sicd", "Hello, world!", 10, 'a', 1.234567);    // 문자열, 정수, 문자, 실수
	
	printfNumbers_string("---------------\n");
	printf("%f\n", average(3, 1, 2, 3) );
	return (0);
}
