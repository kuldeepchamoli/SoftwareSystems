/*
============================================================================
Name : create.c
Author : Kuldeep Chamoli
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call.
Date: 17th August, 2024.
============================================================================
*/
#include <fcntl.h>     
#include <stdio.h>     
#include <unistd.h>    
#include <errno.h>     

int main() {
    const char *f = "file1.txt";  // Name of the file to be created f
    int fd;//fd

    // Using creat() to create the file with read/write permissions for the owner (user)
    fd = creat(f, S_IRUSR | S_IWUSR);

    if (fd == -1) {
        // If the file descriptor is -1, an error occurred
        perror("Error creating the file");
        return 1;  //  non-zero indicate an error
    }

    printf("File created successfully with file descriptor: %d\n", fd);

    close(fd);

    return 0;  // Return 0 to indicate success
}
