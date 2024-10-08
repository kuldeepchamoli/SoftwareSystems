/*
============================================================================
Name : har.c
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

int main() {
    const char *original = "/home/kuldeep-chamoli/Desktop/SoftwareSystems101-main/q1.2b/assiq1.2b/original.txt";
    const char *linkpath = "hardlinktooriginal";

    // Create the hard link
    int result = link(original, linkpath);

    if (result == 0) {
        printf("Hard link created successfully: %s -> %s\n", linkpath, original);
    } else {
        perror("Error creating hard link");
    }

    return 0;
}

