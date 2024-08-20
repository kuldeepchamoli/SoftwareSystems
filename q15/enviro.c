/*
============================================================================
Name : 15 enviro.c
Author : Kuldeep Chamoli
Description : Write a program to display the environmental variable of the user (use environ).
Date:  20 August 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>

extern char **environ;  

int main() {
    for (char **env = environ; *env != NULL; env++) {
        printf("%s\n", *env);
    }
    return 0;
}
