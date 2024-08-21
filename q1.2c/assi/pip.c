/*
============================================================================
Name : pip.c
Author : Kuldeep Chamoli
Description : Create the following types of a files using (i) shell command (ii) system call
              a. soft link (symlink system call)
              b. hard link (link system call)
              c. FIFO (mkfifo Library Function or mknod system call)
Date: 12th August 2024.
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    const char *fifoPath = "/home/kuldeep-chamoli/Desktop/SoftwareSystems101-main/q1.2c/assi/original.txt";  // Path where the FIFO will be created

    // Create the named pipe (FIFO) with read/write permissions
    int result = mkfifo(fifoPath, 0666);

    if (result == 0) {
        printf("FIFO (named pipe) created successfully: %s\n", fifoPath);
    } else {
        perror("Error creating FIFO");
    }

    return 0;
}
