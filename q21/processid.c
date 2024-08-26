/*
============================================================================
Name : 21 process.id
Author : Kuldeep Chamoli
Description : Write a program, call fork and print the parent and child process id.
Date:  23 August 2024
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
  int pid;
  pid = fork();
  if(pid==0){
  
    printf("The child process id is : %d\n",getpid());
  }
  else{
     printf("The Parent Process id is : %d\n",getpid());
  }
  return 0;
}
