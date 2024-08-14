#include <string.h>
#include <fcntl.h>     // For open() and O_RDONLY
#include <unistd.h>    // For read() and close()
#include <stdio.h>     // For perror(), printf(), and other I/O functions
#include <stdlib.h>    // For exit()

#define BUFFER_SIZE 1024  // Define a buffer size for reading lines

int main(int argc, char *argv[]) {
    int file_descriptor;    // File descriptor for the file
    ssize_t bytes_read;     // Number of bytes read
    char buffer[BUFFER_SIZE];  // Buffer to store read data
    char *buffer_ptr = buffer; // Pointer to traverse the buffer
    char *line_start;       // Pointer to the start of a line

    // Check if the correct number of arguments is provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open the file in read-only mode
    file_descriptor = open(argv[1], O_RDONLY);
    if (file_descriptor == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read and display the file line by line
    while ((bytes_read = read(file_descriptor, buffer_ptr, BUFFER_SIZE - (buffer_ptr - buffer))) > 0) {
        // Point to the start of the buffer
        line_start = buffer;

        // Traverse through the buffer to find newlines
        for (char *ptr = buffer; ptr < buffer_ptr + bytes_read; ptr++) {
            if (*ptr == '\n') {
                // Null-terminate the line and print it
                *ptr = '\0';
                printf("%s\n", line_start);

                // Move to the start of the next line
                line_start = ptr + 1;
            }
        }

        // Handle partial lines
        if (line_start < buffer_ptr + bytes_read) {
            // Shift remaining data to the start of the buffer
            size_t remaining = buffer_ptr + bytes_read - line_start;
            memmove(buffer, line_start, remaining);
            buffer_ptr = buffer + remaining;
        } else {
            buffer_ptr = buffer;
        }
    }

    // If the last line does not end with a newline, print it
    if (buffer_ptr > buffer) {
        *buffer_ptr = '\0';
        printf("%s\n", buffer);
    }

    if (bytes_read == -1) {
        perror("Error reading from file");
    }

    // Close the file descriptor
    close(file_descriptor);

    return 0;
}

