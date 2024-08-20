/*
============================================================================
Name : 14 file_type.c
Author : Kuldeep Chamoli
Description : Write a program to find the type of a file.
              a. Input should be taken from command line.
              b. program should be able to identify any type of a file.
Date:  20 August 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

void print_file_type(const char *f) {//f
    struct stat fs;//fs

    // Get file statistics using stat()
    if (stat(f, &fs) == -1) {
        perror("Error getting file information");
        exit(EXIT_FAILURE);
    }

    printf("File: %s\n", f);
    printf("Type: ");

    // Check the file type using the st_mode field
    if (S_ISREG(fs.st_mode)) {
        printf("Regular file\n");
    } else if (S_ISDIR(fs.st_mode)) {
        printf("Directory\n");
    } else if (S_ISCHR(fs.st_mode)) {
        printf("Character device\n");
    } else if (S_ISBLK(fs.st_mode)) {
        printf("Block device\n");
    } else if (S_ISFIFO(fs.st_mode)) {
        printf("FIFO (named pipe)\n");
    } else if (S_ISLNK(fs.st_mode)) {
        printf("Symbolic link\n");
    } else if (S_ISSOCK(fs.st_mode)) {
        printf("Socket\n");
    } else {
        printf("Unknown type\n");
    }
}

int main(int a, char *ar[]) {
    
    if (a != 2) {
        fprintf(stderr, "Usage: %s filename\n", ar[0]);
        exit(EXIT_FAILURE);
    }

    // Print file type
    print_file_type(ar[1]);

    return 0;
}
