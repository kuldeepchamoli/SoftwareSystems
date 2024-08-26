/*
============================================================================
Name : 20 priority.c
Author : Kuldeep Chamoli
Description :Find out the priority of your running program. Modify the priority with nice command.
Date:  23 August,2024.
============================================================================
*/
#include <unistd.h> 
#include <stdio.h>  
#include <stdlib.h> 

void main(int argc, char *argv[])//argchar(count no. of file passed) is integer val while argval is character
{
    int priority;
    int newpriori;
    if (argc != 2)//(if there is no second arg regarding npriority change return error msg
        printf("Please pass the integer value to be added to the current nice value\n");
    else
    {
        newpriori = atoi(argv[1]);
        priority = nice(0); 
        printf("Current priority: %d\n", priority);//nice -n <niceness_value> ./check_priority
        priority = nice(newpriori);
        printf("New priority: %d\n", priority);
    }
}
