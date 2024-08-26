#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    pid_t pid = getpid();
    int priority = getpriority(PRIO_PROCESS, pid);

    printf("Current priority (niceness) of the process: %d\n", priority);

    return 0;
}
