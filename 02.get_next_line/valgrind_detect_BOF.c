#include <stdio.h>
#include <stdlib.h>

/* gcc -Wall -Werror -Wextra 로 컴파일해도 잘 실행됨.
valgrind ./a.out 으로 검사하여도 마찬가지.
but, gcc -fsanitize=address 로 컴파일하면 , heap buffer overflow가 발생한다.
printf로 temp를 읽어줄 때, temp에 할당된 크기를 벗어나는 것을 체크해주는 옵션으로 생각됨!
*/
char	*return_malloc(void)
{
	char *temp;
	temp = malloc(5);
	// temp[4] = 0;
	return (temp);
}

int main()
{
	char *temp = NULL;
	temp = return_malloc();
	printf("%s\n", temp);
	free(temp);
	return (1);
}