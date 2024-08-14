#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s </home/kuldeep-chamoli/Desktop/SoftwareSystems101-main/q9>\n", argv[0]);
        return 1;
    }

    const char *file_path = argv[1];
    struct stat file_stat;

    if (stat(file_path, &file_stat) == -1) {
        perror("stat");
        return 1;
    }

    printf("File: %s\n", file_path);
    printf("a. Inode: %lu\n", file_stat.st_ino);
    printf("b. Number of hard links: %lu\n", file_stat.st_nlink);
    printf("c. UID: %u\n", file_stat.st_uid);
    printf("d. GID: %u\n", file_stat.st_gid);
    printf("e. Size: %ld bytes\n", file_stat.st_size);
    printf("f. Block size: %ld bytes\n", file_stat.st_blksize);
    printf("g. Number of blocks: %ld\n", file_stat.st_blocks);
    printf("h. Time of last access: %s", ctime(&file_stat.st_atime));
    printf("i. Time of last modification: %s", ctime(&file_stat.st_mtime));
    printf("j. Time of last change: %s", ctime(&file_stat.st_ctime));

    return 0;
}
