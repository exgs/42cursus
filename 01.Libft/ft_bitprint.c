#include <stdio.h>
//https://blog.naver.com/tipsware/221247339533
//http://blog.naver.com/PostView.nhn?blogId=tipsware&logNo=221360791167
int main()
{
	int bit_criteria[8] = {128,64,32,16,8,4,2,1};
	unsigned int data = 0;
	printf("255이하의 값을 입력해주세요 : ");
	scanf("%hhd",&data);
	printf("%d : ",data);
	for (size_t i = 0; i < 8; i++)
	{
		if (data & bit_criteria[i])
			printf("1");
		else
			printf("0");
	}
	printf("\n");
}
