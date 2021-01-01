#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
// #include <sys/types.h>

int main(int argc, char **argv)
{
      int pid;
      int sig_num;
	

      if (argc != 3)
      {
          printf("usage %s [pid] [signum]\n", argv[0]);
          return 1;
      }
      // 실행인자로 pid 번호와 
      // 전송할 signal 번호를 받아들여서 
      // 이를 해당 pid 로 보낸다. 
      pid = atoi(argv[1]);
      sig_num = atoi(argv[2]);
      if(kill(pid, sig_num))
      {
          perror("Signal Send error");
          return 1;
      }
	  printf("good\n");
      return 0;
  }