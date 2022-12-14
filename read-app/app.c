#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "thpool.h"
#include "file.h"


int main() {
    // open threads for each task
    puts("Making threadpool with 4 threads");
	threadpool thpool = thpool_init(4);

    // thread to read from file
    thpool_add_work(thpool, stdinRead, (char *)"stdinRead");
    thpool_add_work(thpool, open_read_file, (char *)"filename");

    // thread to read from socket 

	thpool_wait(thpool);
	puts("Killing threadpool");
	thpool_destroy(thpool);
	
	return 0;

    

    // thread to read from pipe

}