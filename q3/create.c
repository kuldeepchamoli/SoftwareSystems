#include <fcntl.h>     // For creat() and O_CREAT
#include <stdio.h>     // For printf()
#include <unistd.h>    // For close()
#include <errno.h>     // For errno and perror()

int main() {
    const char *filename = "file1.txt";  // Name of the file to be created
    int file_descriptor;

    // Using creat() to create the file with read/write permissions for the owner (user)
    file_descriptor = creat(filename, S_IRUSR | S_IWUSR);

    if (file_descriptor == -1) {
        // If the file descriptor is -1, an error occurred
        perror("Error creating the file");
        return 1;  // Return non-zero to indicate an error
    }

    // Print the file descriptor value
    printf("File created successfully with file descriptor: %d\n", file_descriptor);

    // Close the file descriptor to release the resource
    close(file_descriptor);

    return 0;  // Return 0 to indicate success
}
