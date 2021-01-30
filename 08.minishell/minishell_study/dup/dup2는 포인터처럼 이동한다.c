#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

int main(void){
        int fd1, ret;
        char message[32]={"STDERR from fd1\n"};

        fd1=open("made_by_fd1",O_RDWR|O_CREAT | O_TRUNC, S_IRUSR|S_IWUSR);
        if(fd1<0){
                printf("file open error\n");
                exit(0);
        }
        printf("file open\n");
        ret=dup2(fd1,STDOUT_FILENO);
        printf("fd1 :%d, ret:%d\n",fd1,ret);
		
        ret=dup2(STDERR_FILENO,fd1);
        write(fd1,message,strlen(message));
        printf("printf를 썼지만 파일에 기록됨 \n");
		
		//다시 되돌아옴 fd1 초기값으로
		ret = dup2(STDOUT_FILENO, fd1); 
		write(fd1,message,strlen(message));
        close(fd1);

}