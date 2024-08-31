/*
============================================================================
Name : move.c
Author : Kuldeep Chamoli
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 20th August, 2024.
============================================================================
*/
#include <fcntl.h>     
#include <unistd.h>    
#include <stdio.h>     
#include <stdlib.h>    

#define BUFFER_SIZE 1024  

int main(int argc, char *argv[]) {
    int source_fd, dest_fd;   
    ssize_t bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];

    
    if (argc != 3) {
        fprintf(stderr, "Usage: %s source_file destination_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open the source file for reading
    source_fd = open(argv[1], O_RDONLY);
    if (source_fd == -1) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    // Open the destination file for writing (create if it doesn't exist, truncate if it does)
    dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (dest_fd == -1) {
        perror("Error opening/creating destination file");
        close(source_fd);
        exit(EXIT_FAILURE);
    }

    
    while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Error writing to destination file");
            close(source_fd);
            close(dest_fd);
            exit(EXIT_FAILURE);
        }
    }

    if (bytes_read == -1) {
        perror("Error reading from source file");
    }

    // Close both files
    close(source_fd);
    close(dest_fd);

    return 0;
}

