/*============================================================================
Name : 27 execute.c
Author : Kuldeep Chamoli
Description : 27. Write a program to execute ls -Rl by the following system calls
                a. execl
                b. execlp
                c. execled. 
                d. execv
                e. execvp
Date:  28,August 2024
============================================================================
*/
#include <stdio.h>   
#include <stdlib.h>  
#include <unistd.h>  

int main() {
    // First execution using execl
    printf("Using execl:\n");  // Print the method being used
    if (fork() == 0) {         // Create a child process using fork
        // In the child process
        execl("/bin/ls", "ls", "-Rl", NULL);  // Execute 'ls -Rl' using execl
        perror("execl");       // If execl fails, print an error message
        exit(1);               // Exit the child process with an error code
    }

    // Second execution using execlp
    printf("\nUsing execlp:\n");  // Print the method being used
    if (fork() == 0) {            // Create another child process using fork
        // In the child process
        execlp("ls", "ls", "-Rl", NULL);  // Execute 'ls -Rl' using execlp
        perror("execlp");         // If execlp fails, print an error message
        exit(1);                  // Exit the child process with an error code
    }

    // Third execution using execle
    printf("\nUsing execle:\n");  // Print the method being used
    char *envp[] = { NULL };      // Define an empty environment (default)
    if (fork() == 0) {            // Create another child process using fork
        // In the child process
        execle("/bin/ls", "ls", "-Rl", NULL, envp);  // Execute 'ls -Rl' using execle
        perror("execle");         // If execle fails, print an error message
        exit(1);                  // Exit the child process with an error code
    }

    // Fourth execution using execv
    printf("\nUsing execv:\n");  // Print the method being used
    if (fork() == 0) {           // Create another child process using fork
        // In the child process
        char *args[] = { "/bin/ls", "ls", "-Rl", NULL };  // Define arguments as an array
        execv("/bin/ls", args);  // Execute 'ls -Rl' using execv
        perror("execv");         // If execv fails, print an error message
        exit(1);                 // Exit the child process with an error code
    }

    // Fifth execution using execvp
    printf("\nUsing execvp:\n");  // Print the method being used
    if (fork() == 0) {            // Create another child process using fork
        // In the child process
        char *args[] = { "ls", "-Rl", NULL };  // Define arguments as an array
        execvp("ls", args);  // Execute 'ls -Rl' using execvp
        perror("execvp");    // If execvp fails, print an error message
        exit(1);             // Exit the child process with an error code
    }

    return 0;  
}
