/*============================================================================
Name : 29 schedule.c
Author : Kuldeep Chamoli
Description : 29. Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
              SCHED_RR).
Date:  28,August 2024
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>

int main() {
    int policy_name;
    struct sched_param param;

    // Get the current scheduling policy
    policy_name = sched_getscheduler(0);  // 0 means the current process

    if (policy_name  == -1) {
        perror("sched_getscheduler");
        exit(EXIT_FAILURE);
    }

    // Print the current scheduling policy
    printf("Current scheduling policy: ");
    switch (policy_name ) {
        case SCHED_OTHER:
            printf("SCHED_OTHER\n");
            break;
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
        default:
            printf("Unknown\n");
    }

    // Set the priority
    param.sched_priority = 10;  // Set the priority to 10 (valid for SCHED_FIFO or SCHED_RR)

    // Modify the scheduling policy to SCHED_FIFO
    if (sched_setscheduler(0, SCHED_FIFO, &param) == -1) {
        perror("sched_setscheduler SCHED_FIFO");
        exit(EXIT_FAILURE);
    }

    printf("Scheduling policy changed to SCHED_FIFO with priority %d\n", param.sched_priority);

    // Check the scheduling policy again
    policy_name  = sched_getscheduler(0);
    if (policy_name  == -1) {
        perror("sched_getscheduler");
        exit(EXIT_FAILURE);
    }

    // Print the updated scheduling policy
    printf("Updated scheduling policy: ");
    switch (policy_name ) {
        case SCHED_OTHER:
            printf("SCHED_OTHER\n");
            break;
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
        default:
            printf("Unknown\n");
    }

    // Modify the scheduling policy to SCHED_RR
    if (sched_setscheduler(0, SCHED_RR, &param) == -1) {
        perror("sched_setscheduler SCHED_RR");
        exit(EXIT_FAILURE);
    }

    printf("Scheduling policy changed to SCHED_RR with priority %d\n", param.sched_priority);

    // Check the scheduling policy again
    policy_name  = sched_getscheduler(0);
    if (policy_name  == -1) {
        perror("sched_getscheduler");
        exit(EXIT_FAILURE);
    }

    // Print the final scheduling policy
    printf("Final scheduling policy: ");
    switch (policy_name ) {
        case SCHED_OTHER:
            printf("SCHED_OTHER\n");
            break;
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
        default:
            printf("Unknown\n");
    }

    return 1;
}
