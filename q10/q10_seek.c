#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *filename = "example.txt";
    const char *data1 = "ABCDEFGHIJ";  // 10 bytes
    const char *data2 = "1234567890";  // 10 bytes
    int fd;

    // Open the file with read-write mode, create it if it doesn't exist
    fd = open(filename, O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Write the first 10 bytes
    if (write(fd, data1, strlen(data1)) == -1) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }

    // Move the file pointer by 10 bytes using lseek
    off_t offset = lseek(fd, 10, SEEK_CUR);
    if (offset == (off_t)-1) {
        perror("Error using lseek");
        close(fd);
        return 1;
    }
    printf("lseek return value: %ld\n", (long)offset);

    // Write the second 10 bytes
    if (write(fd, data2, strlen(data2)) == -1) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }

    // Close the file
    close(fd);
    printf("Data written to file '%s'.\n", filename);

    return 0;
}
