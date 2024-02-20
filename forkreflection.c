#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void sigquit();

int main(int argc, char **argv[]) {
	
	int forkid = fork();

	if (forkid == 0) {
		printf("Child Process, PID: %d, forkid: %d\n", getpid(), forkid);
		signal(SIGQUIT, sigquit);
		while(1);		
	} else {
		printf("Parent Process, PID: %d, forkid: %d\n", getpid(), forkid);
		printf("Sending quit signal to child...\n");

		sleep(3);
		kill(forkid, SIGQUIT);	
	}

	return 0;
}

void sigquit() {
	printf("Child has received signal\n");
	exit(0);
}
