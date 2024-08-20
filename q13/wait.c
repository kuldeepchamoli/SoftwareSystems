/*
============================================================================
Name : 13 wait.c
Author : Kuldeep Chamoli
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date:  20 August 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/time.h>
#include <errno.h>

int main() {
    struct timeval t;//t    
    fd_set f;  //f      
    int r;//r

    
    t.tv_sec = 10;//timeout for 10
    t.tv_usec = 0;

    
    FD_ZERO(&f);//file desc
    FD_SET(STDIN_FILENO, &f);  

  
    printf("Waiting for input on STDIN for 10 seconds...\n");
    r = select(STDIN_FILENO + 1, &f, NULL, NULL, &t);

    if (r == -1) {

        perror("select()");
        exit(EXIT_FAILURE);
    } else if (r) {
  
        printf("Data is available on STDIN.\n");

        
        char buffer[1024];
        ssize_t bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
        if (bytes_read > 0) {
            buffer[bytes_read] = '\0';
            printf("Read: %s\n", buffer);
        } else {
            perror("Error reading STDIN");
        }
    } else {
        printf("No data was available within 10 seconds.\n");
    }

    return 0;
}

