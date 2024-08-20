/*
============================================================================
Name : q16 lock.c
Author : Kuldeep Chamoli
Description : Write a program to perform mandatory locking.
              a. Implement write lock
              b. Implement read lock
Date:  20 August 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


int main() {
    char buffer[256];
    int fd = open("new.txt", O_RDWR | O_CREAT);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    struct flock lock;
    lock.l_type = F_WRLCK;   
    lock.l_whence = SEEK_SET; 
    lock.l_start = 0;         
    lock.l_len = 0;           
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl write lock");
        exit(EXIT_FAILURE);
    }
    printf("Write lock acquired. Press Enter to release it.\n");
    getchar(); 
    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("fcntl unlock");
        exit(EXIT_FAILURE);
    }
    printf("Write lock released.\n");
    lock.l_type = F_RDLCK;
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl read lock");
        exit(EXIT_FAILURE);
    }
    printf("Read lock acquired. Press Enter to release it.\n");
    getchar(); 
    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("fcntl unlock");
        exit(EXIT_FAILURE);
    }
    printf("Read lock released.\n");
    close(fd);
    return 0;
}
