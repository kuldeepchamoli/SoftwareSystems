/*
============================================================================
Name : read_write.c
Author : Kuldeep Chamoli
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 20th August, 2024.
============================================================================
*/
#include <unistd.h>  // For read() and write() system calls
#include <stdio.h>   // For perror()

#define BUFFER_SIZE 1024  // Define a buffer size

int main() {
    char buffer[BUFFER_SIZE];  // Buffer to store input
    ssize_t bytes_read;        // Number of bytes read

    // Read from STDIN (file descriptor 0) into the buffer
    bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);

    if (bytes_read == -1) {
        // If there's an error, print it using perror
        perror("Error reading from STDIN");
        return 1;  // Return non-zero to indicate an error
    }

    // Write the data from the buffer to STDOUT (file descriptor 1)
    ssize_t bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

    if (bytes_written == -1) {
        // If there's an error, print it using perror
        perror("Error writing to STDOUT");
        return 1;  // Return non-zero to indicate an error
    }

    return 0;  // Return 0 to indicate success
}
