/*
================================================
Author : Kuldeep Chamoli

Description :
Write a program to create an orphan process.
================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        // Parent process
        printf("Parent process PID: %d\n", getpid());
        printf("Child process PID: %d\n", pid);
        exit(0); // Parent exits, child becomes an orphan
    } else if (pid == 0) {
        // Child process
        sleep(5); // Sleep to simulate work and allow time for orphaning
        printf("Orphan child process PID: %d, Parent PID: %d\n", getpid(), getppid());
        system("ps -o pid,ppid,stat,cmd"); // Display processes to show orphan status
    } else {
        // Fork failed
        perror("fork");
        exit(EXIT_FAILURE);
    }

    return 0;
}
