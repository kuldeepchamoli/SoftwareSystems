/*
============================================================================
Name :raed_write_lock.c
Author : Kuldeep Chamoli
Description : Write a program to perform Record locking.
              a. Implement write lock
              b. Implement read lock
              Create three records in a file. Whenever you access a particular record, first lock it then modify/access
              to avoid race condition.
Date:  20 August 2024.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include <stddef.h>


int rlock(int l);
int wlock(int l);

struct student {
    int roll_no;
    int marks;
};

int rlock(int l) {
    int fd=open("new.txt", O_RDONLY);
    if(fd==-1){
      perror("Cant open the file");
      return 1;
    }
    struct student std;
    lseek(fd, (l - 1) * sizeof(struct student), SEEK_SET);
    read(fd, &std, sizeof(struct student));
    printf("Roll No: %d \n Marks : %d \n", std.roll_no, std.marks);
    struct flock lock;
    lock.l_type=F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start =  (l - 1 ) * sizeof(struct student);
    lock.l_len = sizeof(struct student);
    printf("Waiting to acquire lock on record %d \n", std.roll_no);
    fcntl(fd, F_SETLKW, &lock);
    printf("Acquired lock on record %d \n", std.roll_no);
    printf("Press return to exit\n");
    getchar();
    getchar();
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &lock);
    printf("Exited critical section\n");
}


int wlock(int l) {
    int fd=open("new.txt", O_RDWR);
    if(fd < 0) {
       perror("Cant open file");
       return 1;
    }
    struct student std;
    lseek(fd, (l- 1) * sizeof(struct student), SEEK_SET);
    read(fd, &std, sizeof(struct student));
    printf("Roll No: %d \n", std.roll_no);
    printf("Marks : %d\n",std.marks);
    struct flock lock;
    lock.l_type=F_WRLCK;
    lock.l_whence=SEEK_SET;
    lock.l_start=(l- 1) * sizeof(struct student);
    lock.l_len = sizeof(struct student);
    printf("Waiting to acquire lock on record %d \n", std.roll_no);
    lock.l_type=F_WRLCK;
    int r=fcntl(fd, F_SETLKW, &lock);
    if(r < 0){
      perror("Error\n");
      return 1;
    }
    printf("Acquired lock on record %d \n", std.roll_no);
    printf("You selected to write on this record. \nEnter new marks: ");
    int marks;
    scanf("%d", &marks);
    std.marks=marks;
    lseek(fd, -1 * sizeof(struct student), SEEK_CUR);
    write(fd, &std, sizeof(struct student));
    lseek(fd, -1 * sizeof(struct student), SEEK_CUR);
    read(fd, &std, sizeof(struct student));
    printf("Roll No: %d \n", std.roll_no);
    printf("Marks : %d\n",std.marks);
    printf("Press return to exit\n");
    getchar();
    getchar();
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &lock);
    printf("Exited critical section\n");
}

int main() {
    int fd = open("new.txt", O_RDWR);
    if (fd < 0) {
	  perror("file cant be opened\n");
	  exit(1);
    }
    lseek(fd,0,SEEK_SET);
    struct student std;
    read(fd, &std, sizeof(struct student));
    printf("Roll No. : %d\n", std.roll_no);
    printf("Marks : %d\n", std.marks);
    read(fd, &std, sizeof(struct student));
    printf("Roll No. : %d\n", std.roll_no);
    printf("Marks : %d\n", std.marks);
    int l;
    int choice;
    lseek(fd, 0, SEEK_SET);
    printf("Select record you want to lock: ");
    scanf("%d", &l);
    if(l< 1 || l> 2){
      printf("No such record found\n");
      return 0;
    }
    printf("Select type of lock: Read (1) Write (2) Choice: ");
    scanf("%d", &choice);
    if(choice == 1) {
        rlock(l);
        exit(1);
    }
    else if(choice == 2) {
        wlock(l);
        exit(1);
    }
    else {
        printf("Wrong choice!");
    }
    close(fd);
    return 0;
}
