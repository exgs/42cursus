/*
stat_find 파일 코드는 변수를 선언하고 stat의 st_mode와 상수인 S_IFMT의 &연산을 통해 만들어야한다.
stat_macro 파일 코드는 stat의 st_mode를 매크로함수에 넣어 각각 해당 매크로에 따라서 참이면 1 거짓이면 0
*/

/*
매크로를 이용한 파일 종류 검색
<sys/stat.h> 파일에는 상수 외에 매크로도 정의되어 있습니다. 파일의 종류 검색과 관련해 정의되어 있는 매크로는 아래와 같습니다. 이들 매크로는 POSIX 표준입니다.
각 매크로는 인자로 받은 mode 값을 0xF000과 AND 연산을 합니다. AND 연산의 결과를 파일의 종류별로 정해진 값과 비교해 참인지 여부로 파일의 종류를 판단합니다. 
출처: https://12bme.tistory.com/215?category=753165 [길은 가면, 뒤에 있다.]

st_mode: 파일의 형식과 접근 권한을 저장한다
S_ISFIFO(mode), (((mode)&0xF000) == 0x1000), 참이면 FIFO 파일
S_ISDIR(mode), (((mode)&0xF000) == 0x4000), 참이면 디렉토리
S_ISREG(mode), (((mode)&0xF000) == 0x8000), 참이면 일반 파일

상수명, 상수 값(16진수), 기능
S_IFMT, 0xF000, st_mode 값에서 파일의 종류를 정의한 부분을 가져옴
S_IFIFO, 0x1000, FIFO 파일
S_IFDIR, 0x4000, 디렉토리
S_IFREG, 0x8000, 일반 파일
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(void)
{
	struct stat buf;
	stat("unix.txt", &buf);
	printf("Mode = %o (16진수: %x)\n", (unsigned int)buf.st_mode, (unsigned int)buf.st_mode);
	if (S_ISFIFO(buf.st_mode))
		printf("unix.txt : FIFO\n");
	if (S_ISDIR(buf.st_mode))
		printf("unix.txt : Directory\n");
	if (S_ISREG(buf.st_mode))
		printf("unix.txt : Regular File\n");

	int kind;
	kind = buf.st_mode & S_IFMT;
	printf("Kind = %x\n", kind);
	switch(kind)
	{
		case S_IFIFO:
			printf("unix.txt : FIFO\n");
			break ;
		case S_IFDIR:
			printf("unix.txt : Directory\n");
			break ;
		case S_IFREG:
			printf("unix.txt : Regular File\n");
			break ;
	}
	return (0);
}