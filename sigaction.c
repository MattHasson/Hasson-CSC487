#include <stdlib.h>
#include <unistd.h>

int sigaction()
{
    while(1) {
        printf("Run this...%d\n", getpid());
        sleep(1);
    }
}