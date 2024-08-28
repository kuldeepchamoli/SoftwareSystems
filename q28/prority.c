/*============================================================================
Name : 28 priority.c
Author : Kuldeep Chamoli
Description : 28. Write a program to get maximum and minimum real time priority.
Date:  28,August 2024
============================================================================
*/
#include <stdio.h>
#include <sched.h>

int main() {
    int mxpriority= sched_get_priority_max(SCHED_FIFO);
    if (mxpriority == -1) {
        perror("Error\n");
        return 1;
    }
    int minpriority = sched_get_priority_min(SCHED_FIFO);
    if (minpriority== -1) {
        perror("Error\n");
        return 1;
    }
    printf("Maximum real-time priority: %d\n", mxpriority);
    printf("Minimum real-time priority: %d\n", minpriority);

    return 1;
}

