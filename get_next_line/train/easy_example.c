#include <sys/types.h> 
#include <sys/stat.h>
#include <fcntl.h> 
#include <unistd.h>
 #include <stdio.h> 
//  #include <stdlib.h> 
 int main(void) 
 {
    int fd;
    int n;
    char buf[20];
    fd=open("test.txt", O_RDONLY);
    printf(".txt : fd = %d\n", fd); 
    if(fd == -1)
    { 
    perror("Excl");
    } 

    n = read(fd,buf,23);
    buf[n]='\0';
    printf("%d \n%s",n,buf);
    close(fd);
    return 0; 
}