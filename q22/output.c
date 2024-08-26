#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {//no arg inside main () int argc, char * argv[]
    pid_t pid;
    char *filename = "output.txt";

    // Open a file for writing
    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);//man 2 open
    if (fd < 0) {
        perror("Failed to open file");
        return 1;
    }

    // Create a new process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        const char *child_msg = "This is the child process writing to the file.\n";
        write(fd, child_msg, sizeof(child_msg));
        printf("Child process (PID: %d) has written to the file.\n", getpid());
    }
    else {
        // Parent process
        const char *parent_msg = "This is the parent process writing to the file.\n";
        write(fd, parent_msg, sizeof(parent_msg));
        printf("Parent process (PID: %d) has written to the file.\n", getpid());
    }

    // Close the file
    close(fd);

    return 0;
}

