/*
============================================================================
Name : excl.c
Author : Kuldeep Chamoli
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 18th August, 2024.
============================================================================
*/
#include <fcntl.h>     // For open(), O_RDWR, O_EXCL, O_CREAT
#include <stdio.h>     
#include <unistd.h>    // For close()
#include <errno.h>     // For errno and perror()

int main() {
    const char *f = "existing_file.txt";  // f
    int fd;//fd

    
    fd = open(f, O_RDWR);//tryna open fle r/w mode

    if (fd == -1) {
        perror("Error opening the file in read-write mode");
        return 1;  
    }

    printf("File opened successfully with file descriptor: %d\n", fd);

    // Trying to open the file with O_EXCL flag (this will not work as expected without O_CREAT)
    fd = open(f, O_RDWR | O_EXCL);

    if (fd == -1) {
        //  fail  O_EXCL without O_CREAT is not a valid 
        perror("Error opening the file with O_EXCL flag");
    } else {
        // If somehow it doesn't fail (which is not expected), print the file descriptor
        printf("File opened successfully with O_EXCL, file descriptor: %d\n", fd);
        close(fd);
    }
           //Ensures that the call fails if the file already exists. This flag is typically used in combination
//Ensures that the call fails if the file already exists. This flag is typically used in
//combination with O_CREAT to create a file only if it does not already exist. with O_CREAT to create a file only if it does not already exist.
    // Close the file descriptor to release the resource
    close(fd);

    return 0;  
}
