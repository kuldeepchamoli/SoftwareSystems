/*
============================================================================
Name : 22 zombie.c
Author : Kuldeep Chamoli
Description : Write a program to create a Zombie state of the running program.
Date:  26,August 2024
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    
    if (pid > 0) {
        // Parent process sleeps to give time for the child to finish.
        sleep(10);
    } else if (pid == 0) {
        // Child process exits immediately, becoming a zombie.
        exit(0);
    } else {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    
    return 0;
}
