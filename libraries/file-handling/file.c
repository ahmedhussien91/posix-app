#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "file.h"

#define SIZE 1000

void stdinRead(void *arg)
{
    char buf[SIZE];
    
	printf("Thread #%u working on %s\n", (int)pthread_self(), (char*) arg);
    fgets(buf, SIZE , stdin);
    printf("Text from stdin: %s\n", buf);
}

int open_read_file(char * name)
{
    char buf[SIZE];

    printf("Thread #%u working on opening file %s\n", (int)pthread_self(), (char*) name);
    int fd;
    fd = open(name,0);
    if(fd < 0)
    {
        perror("open_read_file() open() failed");
    }

    fd = read(fd, buf, SIZE);
    if(fd < 0)
    {
        perror("open_read_file() read() failed");
    } else {
        printf("text in file: %s", buf);
    }
    
    return fd;
}