#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

void handler(int num) {
    write(STDIN_FILENO, "Not Dying huh...\n", 13);
}

int main(int argc, char *argv[]) {
    int pid = fork();
    if(pid == -1) {
        return 1;
    }
    if (pid == 0) {
        while(1) {
            printf("CSC487 Again...\n");
            sleep(50000);
        }
        signal(SIGSEGV, handler);
    }
    else {
        sleep(1);
        signal(pid, SIGSEGV);
    }
    return 0;
}