/*
============================================================================
Name        : 30 daemon.c
Author      : Kuldeep Chamoli
Description : Write a program to run a script at a specific time using a Daemon process
Date        : 28 August,2024
============================================================================
*/

#include <time.h>     
#include <stdio.h>    
#include <stdlib.h>   
#include <sys/types.h> 
#include <unistd.h>   
#include <sys/stat.h> 

void main(int argc, char *argv[])
{
    time_t currentEpoch, deadlineEpoch;  
    struct tm *deadline;                 // Pointer to tm structure for the deadline time
    pid_t child;                         // Variable to store the process ID of the child process

    // Check if the user provided at least one argument (the hour)
    if (argc < 2)
        printf("Pass at least one argument\n"); // Print an error message if not enough arguments are passed
    else
    {
        // Get the current time in epoch format (seconds since January 1, 1970)
        time(&currentEpoch);

        // Convert the current time to a struct tm representing local time
        deadline = localtime(&currentEpoch);

        // Set the deadline time based on the arguments passed
        // argv[1] is the hour (required)
        deadline->tm_hour = atoi(argv[1]);

        // argv[2] is the minute (optional), default to 0 if not provided
        deadline->tm_min = argv[2] == NULL ? 0 : atoi(argv[2]);

        // argv[3] is the second (optional), default to 0 if not provided
        deadline->tm_sec = argv[3] == NULL ? 0 : atoi(argv[3]);

        // Convert the deadline time structure to epoch format
        deadlineEpoch = mktime(deadline);

        // Create a child process
        if ((child = fork()) == 0)
        {
            // In the child process:
            // Create a new session and detach from the terminal
            setsid();

            // Change the working directory to the root to avoid locking directories
            chdir("/");

            // Reset file mode creation mask to ensure full permissions
            umask(0);

            // Loop until the current time reaches or surpasses the deadline
            do
            {
                // Get the current time
                time(&currentEpoch);
            } while (difftime(deadlineEpoch, currentEpoch) > 0);

            // At the deadline time, print a message
            printf("Boo! Got ya!\n");

            // Exit the child process
            exit(0);
        }

        // Exit the parent process (daemonization step)
        exit(0);
    }
}
