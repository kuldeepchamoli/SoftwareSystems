/*
============================================================================
Name : 19 time.c
Author : Kuldeep Chamoli
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date:  22 August,2024.
============================================================================
*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int main(){
   clock_t time = clock();
   double start = (double)time/CLOCKS_PER_SEC;//start time
   printf("Start time is %f\n",start);
   pid_t pid = getpid();
   time = clock();
   double end = (double)time/CLOCKS_PER_SEC;//end time
   printf("End time is : %f\n",end);
   double f = end-start;
   printf("Total Time Taken is %f\n",f);
   return 0;
}

