/*
============================================================================
Name : q2.1.c
Author : Kuldeep Chamoli
Description : Create the following types of a files using (i) shell command (ii) system call
              a. soft link (symlink system call)
              b. hard link (link system call)
              c. FIFO (mkfifo Library Function or mknod system call)
Date: 12th August 2024.
============================================================================
*/
#include <unistd.h>
#include <stdio.h>
int main()
{
char path[256],name[256];
printf("Enter the path of softlink:");
scanf("%s",path);
printf("Enter the name of softlink :");
scanf("%s",name);
symlink(path,name);
perror("perror");
}
