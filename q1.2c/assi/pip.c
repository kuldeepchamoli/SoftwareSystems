#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    const char *fifoPath = "/home/kuldeep-chamoli/Desktop/SoftwareSystems101-main/q1.2c/assi/original.txt";  // Path where the FIFO will be created

    // Create the named pipe (FIFO) with read/write permissions
    int result = mkfifo(fifoPath, 0666);

    if (result == 0) {
        printf("FIFO (named pipe) created successfully: %s\n", fifoPath);
    } else {
        perror("Error creating FIFO");
    }

    return 0;
}
