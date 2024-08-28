#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2, pid3;
    int status;

    // Create the first child process
    pid1 = fork();
    if (pid1 == 0) {
        // First child process
        printf("First child process (PID: %d) started.\n", getpid());
        sleep(4); // Simulate some work with sleep
        printf("First child process (PID: %d) exiting.\n", getpid());
        exit(1);
    }

    // Create the second child process
    pid2 = fork();
    if (pid2 == 0) {
       
        printf("Second child process (PID: %d) started.\n", getpid());
        sleep(5); 
        printf("Second child process (PID: %d) exiting.\n", getpid());
        exit(2);
    }

    // Create the third child process
    pid3 = fork();
    if (pid3 == 0) {
        // Third child process
        printf("Third child process (PID: %d) started.\n", getpid());
        sleep(7); // Simulate some work with sleep
        printf("Third child process (PID: %d) exiting.\n", getpid());
        exit(3);
    }

    // Parent process waits for the second child to finish
    printf("Parent waiting for the second child (PID: %d) to finish.\n", pid2);
    waitpid(pid2, &status, 0);

    // Check if the child exited normally and print its exit status
    if (WIFEXITED(status)) {
        printf("Parent detected that second child (PID: %d) exited with status %d.\n", pid2, WEXITSTATUS(status));
    } else {
        printf("Parent detected that second child (PID: %d) did not exit normally.\n", pid2);
    }

    // Parent may choose to wait for the remaining children 
    waitpid(pid1, &status, 0); 
    waitpid(pid3, &status, 0);

    printf("Parent process (PID: %d) exiting.\n", getpid());

    return 0;
}

