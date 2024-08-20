/*
============================================================================
Name : 12.c open.c
Author : Kuldeep Chamoli
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date: 20th August, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>

int main(int argc, char * argv[]){
    int fd = open(argv[1], O_RDWR);
    if(fd==-1){
       perror("Cant open the file");
       return 1;
    }
    int flags = fcntl(fd,F_GETFL);
    if(flags==-1){
       perror("Error");
       return 1;
    }
    if(flags==32768){
       printf("The file is opened in O_RDONLY mode.\n");
    }
    else if(flags==32769){
       printf("The file is opened in O_WRONLY mode.\n");
    }
    else{
       printf("The file is opened in O_RDWR mode.\n");
    }
    return 0;
}
