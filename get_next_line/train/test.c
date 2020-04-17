#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/fcntl.h>
#define BUFFER_SIZE = 4


int is_replaced_zero(char *buf)
{
    int i = 0;
    printf("%d\n",sizeof(buf));
    while (i < sizeof(buf)) //고쳤어 -1
    {
        if(buf[i] == '\0')
        {
            return (1);
        }
        i++;
    }
    return (0);
}

int main()
{
    printf("%s","11\r");
    return 0;
}