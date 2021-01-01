/*
파일 접근 권한 검색
: 파일의 접근 권한도 st_mode의 값으로 알 수 있다. 이외에도 사용자가 파일에 대한 접근 권한이 있는 지
확인할 수 있는 access 같은 함수가 제공된다.
*/
/*	
상수를 이용한 파일 접근 권한 검색
S_IREAD(00400) -> st_mode 값과 AND 연산으로 소유자의 읽기 권한 확인
S_IRGRP(00040) -> 그룹 읽기 권한
S_IROTH(00004) -> 기타 사용자 읽기 권한
*/
/*
반면에 함수를 사용해 접근 권한을 검색할 수 있습니다.
#include <unistd.h>
int access(const char *path, int amode);
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	struct stat buf;

	stat("unix.txt", &buf);
	printf("Mode = %o (16진수 : %x)\n", (unsigned int)buf.st_mode, (unsigned int)buf.st_mode);

	/* st_mode : 파일의 형식과 접근 권한을 저장한다. */
	/* S_IREAD (상수 값 00400): st_mode 값과 AND 연산으로 소유자의 읽기 권한 확인 */
	if ((buf.st_mode & S_IREAD) != 0) 
		printf("unix.txt : user has a read permission\n");
	/* S_IRGRP (상수 값 00040): st_mode 값과 AND 연산으로 그룹의 읽기 권한 확인 */
	/* 여기서는 S_IREAD를 상수값을 비트쉬프트로 8을 나누어 S_IRGRP의 상수값과 똑같이 해본 코드*/
	if ((buf.st_mode & (S_IREAD >> 3)) != 0)
		printf("unix.txt : group has a read permission\n");
	if ((buf.st_mode & S_IRGRP) != 0)
		printf("unix.txt : group has a read permission\n");

	/* S_IROTH : 기타 사용자 읽기 권한 */
	if ((buf.st_mode & S_IROTH) != 0)
		printf("unix.txt : other have a read permission\n");
		
	if (access("unix.txt", S_IROTH) == 0)
		printf("unix.txt : other have a read permission\n");
	
	return (0);
}