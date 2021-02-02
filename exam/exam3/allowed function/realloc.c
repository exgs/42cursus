#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
int main()
{
	int i, n, m;	//i:for문용 변수, n:arr배열의 처음크기, m:arr배열을 얼마나 증가시킬지
	int *arr;	//포인터 배열
	printf("몇개의 숫자 데이터를 입력하실건가요? : ");
	scanf("%d", &n);
	arr=(int *)malloc(n*sizeof(int));	//입력받은 n만큼 동적할당
	for(i=0; i<=n-1; i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("입력된 데이터는 ");
	for(i=0; i<=n-1; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("입니다\n");
	printf("추가로 몇개의 숫자 데이터를 입력하실건가요? : ");
	scanf("%d", &m);
	arr=(int *)realloc(arr, (m+n)*sizeof(int));	//입력받은 m만큼 추가로 동적할당
	//덮어쓰는 것 처럼 보이지만, 함수 내부적으로 free를 해주고 할당해주나봄
	system("leaks a.out");
	sleep(2);
	for(i = 0; i<=n+m-1; i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("입력된 데이터는 ");
	for(i=0; i<=n+m-1; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("입니다\n");
	free(arr);
	arr = NULL;
	system("leaks a.out");
}