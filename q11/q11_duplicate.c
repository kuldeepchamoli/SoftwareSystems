/*
============================================================================
Name : 11 q11_duplicate.c
Author : Kuldeep Chamoli
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not.
              a. use dup
              b. use dup2
              c. use fcntl
Date: 20th August, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *filename = "example.txt";
    const char *data1 = "Data with dup\n";
    const char *data2 = "Data with dup2\n";
    const char *data3 = "Data with fcntl\n";
    int fd, fd_dup, fd_dup2, fd_fcntl;

    // Open the file in append mode
    fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // 1. Duplicate the file descriptor using dup
    fd_dup = dup(fd);
    if (fd_dup == -1) {
        perror("Error duplicating file descriptor with dup");
        close(fd);
        return 1;
    }

    // Append data using the duplicated file descriptor (dup)
    if (write(fd_dup, data1, strlen(data1)) == -1) {
        perror("Error writing to file with dup");
        close(fd);
        close(fd_dup);
        return 1;
    }

    // 2. Duplicate the file descriptor using dup2
    fd_dup2 = dup2(fd, 100);  // Duplicate to file descriptor 100
    if (fd_dup2 == -1) {
        perror("Error duplicating file descriptor with dup2");
        close(fd);
        close(fd_dup);
        return 1;
    }

    // Append data using the duplicated file descriptor (dup2)
    if (write(fd_dup2, data2, strlen(data2)) == -1) {
        perror("Error writing to file with dup2");
        close(fd);
        close(fd_dup);
        close(fd_dup2);
        return 1;
    }

    // 3. Duplicate the file descriptor using fcntl
    fd_fcntl = fcntl(fd, F_DUPFD, 0);
    if (fd_fcntl == -1) {
        perror("Error duplicating file descriptor with fcntl");
        close(fd);
        close(fd_dup);
        close(fd_dup2);
        return 1;
    }

    // Append data using the duplicated file descriptor (fcntl)
    if (write(fd_fcntl, data3, strlen(data3)) == -1) {
        perror("Error writing to file with fcntl");
        close(fd);
        close(fd_dup);
        close(fd_dup2);
        close(fd_fcntl);
        return 1;
    }

    // Close all file descriptors
    close(fd);
    close(fd_dup);
    close(fd_dup2);
    close(fd_fcntl);

    printf("Data appended successfully. Check the file '%s' to verify.\n", filename);

    return 0;
}
