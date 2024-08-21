/*
============================================================================
Name : five_file.c
Author : Kuldeep Chamoli
Description : Write a program to create five new files with infinite loop. Execute the program in the background
              and check the file descriptor table at /proc/pid/fd.
Date: 18th August, 2024.
============================================================================
*/
#include <fcntl.h>     // For open(), O_CREAT, O_WRONLY
#include <stdio.h>     
#include <unistd.h>    
#include <errno.h>     // For errno and perror()

int main() {
    int fds[5];  // Array to hold file descriptors fds
    const char *f[] = {//f
        "file1.txt",
        "file2.txt",
        "file3.txt",
        "file4.txt",
        "file5.txt"
    };

    // Create five new files
    for (int i = 0; i < 5; i++) {
        fds[i] = open(f[i], O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
        if (fds[i] == -1) {
            perror("Error creating file");
            return 1;
        }
        printf("Created %s with file descriptor: %d\n", f[i], fds[i]);
    }

    // infinite loop
    while (1) {
        sleep(1);  // Sleep for 1 second in each loop iteration to avoid consuming too much CPU
    }

    // This code will never be reached because of the infinite loop,
    for (int i = 0; i < 5; i++) {
        close(fds[i]);
    }

    return 0;
}
