#include <unistd.h>
#include <stdio.h>
#include <sys/fcntl.h>
#include <string.h>

int main()
{
	char buffer[10];
	int fd1; int fd2; int fd3; int fd4;int fd5; int fd6; int fd7; int fd8;int fd9; int fd10; int fd11; int fd12;
	fd1 = open("./test_files/test",O_RDONLY);
	printf("%d\n",fd1);
	printf("read return : %zd\n",read(fd1,buffer,10));
	printf("%s\n",buffer);
	memset(buffer,0,10);
	printf("/*-------------------------------------*/\n");
	
	/*-------------------------------------*/
	fd2 = open("./test_files/test1",O_RDONLY);
	printf("%d\n",fd2);
	printf("read return : %zd\n",read(fd2,buffer,10));
	printf("%s\n",buffer);
	memset(buffer,0,10);
	printf("/*-------------------------------------*/\n");
	
	/*--------------파일을 찾지 못했을 때, open, read ==> -1-----------------------*/
	fd3 = open("./test_files/test10",O_RDONLY);
	printf("%d\n",fd3); //파일을 찾지못하였을 떄 return -1
	printf("read return : %zd\n",read(fd3,buffer,10));
	printf("%s\n",buffer);
	memset(buffer,0,10);
	printf("/*-------------------------------------*/\n");
	
	/*--------------음수의 file descriptor, open, read ==> -1----------------------*/
	fd4 = open("./test_files/test10",O_RDONLY);
	printf("%d\n",fd4); //이상한 숫자가 들어갈때, return -1
	printf("read return : %zd\n",read(fd4,buffer,10));
	printf("%s\n",buffer);
	memset(buffer,0,10);
	printf("/*-------------------------------------*/\n");
	
	/*---------------0byte를 읽으라고 명령할 때, return -1--------------------*/
	fd5 = open("./test_files/test2",O_RDONLY);
	printf("%d\n",fd5);
	printf("0byte, read return : %zd\n",read(fd5,buffer,0));
	printf("%s\n",buffer);
	memset(buffer,0,10);
	printf("/*-------------------------------------*/\n");
	
	/*-----------------read 함수는 도대체 어느시점에 return 0을 해줄까??--------------------
	-------------------read함수는 return 값은 읽는 byte수를 의미한다. 따라서 아예 읽는 것이 없을때!*/	
	fd6 = open("./test_files/test6",O_RDONLY);
	printf("%d\n",fd6);
	printf("read return : %zd\n",read(fd6,buffer,10));
	printf("%s\n",buffer);
	memset(buffer,0,10);
	printf("/*-------------------------------------*/\n");
	
	/*-----------------read에서 fd값이 1000 일때?-----------------*/
	
	fd7 = 1000;
	printf("%d\n",fd7);
	printf("read return : %zd\n",read(fd7,buffer,10));
	printf("%s\n",buffer);
	memset(buffer,0,10);
	printf("/*-------------------------------------*/\n");
	
	close(fd1);close(fd2);close(fd3);close(fd4);
	close(fd5);close(fd6);close(fd7);
	return (0);
}