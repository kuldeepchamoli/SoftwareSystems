#include <fcntl.h>     // For open(), O_RDWR, O_EXCL, O_CREAT
#include <stdio.h>     // For printf()
#include <unistd.h>    // For close()
#include <errno.h>     // For errno and perror()

int main() {
    const char *filename = "existing_file.txt";  // Name of the file to be opened
    int file_descriptor;

    // Trying to open an existing file in read-write mode
    file_descriptor = open(filename, O_RDWR);

    if (file_descriptor == -1) {
        // If the file descriptor is -1, an error occurred
        perror("Error opening the file in read-write mode");
        return 1;  // Return non-zero to indicate an error
    }

    // Print the file descriptor value
    printf("File opened successfully with file descriptor: %d\n", file_descriptor);

    // Trying to open the file with O_EXCL flag (this will not work as expected without O_CREAT)
    file_descriptor = open(filename, O_RDWR | O_EXCL);

    if (file_descriptor == -1) {
        // This should fail because O_EXCL without O_CREAT is not a valid combination
        perror("Error opening the file with O_EXCL flag");
    } else {
        // If somehow it doesn't fail (which is not expected), print the file descriptor
        printf("File opened successfully with O_EXCL, file descriptor: %d\n", file_descriptor);
        close(file_descriptor);
    }
           //Ensures that the call fails if the file already exists. This flag is typically used in combination
//Ensures that the call fails if the file already exists. This flag is typically used in combination with O_CREAT to create a file only if it does not already exist. with O_CREAT to create a file only if it does not already exist.
    // Close the file descriptor to release the resource
    close(file_descriptor);

    return 0;  // Return 0 to indicate success
}
