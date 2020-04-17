#include <unistd.h>
#include <sys/fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 2
#endif

int get_next_line(int fd, char** line);