/*
<함수 원형 및 설명>
int		chmod(const char *filename, int pmode);
filename : 파일의 경로
pmode : 파일에 설정한 접근 모드 값
반환 값 : 정상일 때 0, 에러 시 -1
*/

#include <stdio.h>
#include <sys/stat.h> // _S_IREAD, S_IWRITE

int main()
{
	char strPath[] = {"test.txt"};
	/*관전 포인트: mode는 8진법이 기본이기 때문에 8진법인 것을 생각하고 앞에 0을 붙인다*/
	int nResult = chmod(strPath, 0777);

	if (nResult == 0)
	{
		printf("읽기 전용으로 속성 변경 성공\n");
	}
	else if (nResult == -1)
	{
		perror("실패\n");
	}
	return (0);
}