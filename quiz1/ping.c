#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void sigchld(); 
void sigquit();
int num_of_pings = 0;


int main(int argc, char **argv) {
	
	int forkid = fork();

    if (forkid == 0) {
        printf("Child Process, PID: %d, forkid: %d\n", getpid(), forkid);
        signal(SIGCHLD, sigchld);
		signal(SIGQUIT, sigquit);
        while(1);
    } else {
        printf("Parent Process, PID: %d, forkid: %d\n", getpid(), forkid);
        printf("Pinging child...\n");
		sleep(1);
        kill(forkid, SIGCHLD);
		sleep(1);
        kill(forkid, SIGCHLD);
		sleep(1);
        kill(forkid, SIGCHLD);
		sleep(1);
        kill(forkid, SIGCHLD);
		sleep(1);
        kill(forkid, SIGQUIT);
    }

	return 0;
}

void sigchld() {
	num_of_pings++;
	printf("Number of Pings: %d\n", num_of_pings);
}
void sigquit() {
	printf("Total pings: %d\n", num_of_pings);
	printf("Exiting...\n");
	exit(0);
}
