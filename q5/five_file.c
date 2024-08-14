#include <fcntl.h>     // For open(), O_CREAT, O_WRONLY
#include <stdio.h>     // For printf()
#include <unistd.h>    // For close()
#include <errno.h>     // For errno and perror()

int main() {
    int file_descriptors[5];  // Array to hold file descriptors
    const char *filenames[] = {
        "file1.txt",
        "file2.txt",
        "file3.txt",
        "file4.txt",
        "file5.txt"
    };

    // Create five new files
    for (int i = 0; i < 5; i++) {
        file_descriptors[i] = open(filenames[i], O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
        if (file_descriptors[i] == -1) {
            perror("Error creating file");
            return 1;
        }
        printf("Created %s with file descriptor: %d\n", filenames[i], file_descriptors[i]);
    }

    // Enter an infinite loop
    while (1) {
        sleep(1);  // Sleep for 1 second in each loop iteration to avoid consuming too much CPU
    }

    // This code will never be reached because of the infinite loop,
    // but if you had an exit condition, you would close the file descriptors like this:
    for (int i = 0; i < 5; i++) {
        close(file_descriptors[i]);
    }

    return 0;
}
