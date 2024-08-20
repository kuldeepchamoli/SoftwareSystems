/*
============================================================================
Name : 17_1 wr_lock.c
Author : Kuldeep Chamoli
Description : Write a program to simulate online ticket reservation. Implement write lock
              Write a program to open a file, store a ticket number and exit. Write a separate program, to
              open the file, implement write lock, read the ticket number, increment the number and print
              the new ticket number then close the file.
Date: 20 August 2024.
============================================================================
*/
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main() {
  struct flock lock;
  int fd=open("fl.txt", O_RDWR);
  if(fd==-1){
    perror("Error");
    return 1;
  }
  lock.l_whence = SEEK_SET;
  lock.l_start = 0;
  lock.l_len = 0;
  int buffer;
  lock.l_type=F_RDLCK;
  printf("Read lock set\n");
  fcntl(fd, F_SETLKW, &lock);
  read(fd, &buffer, sizeof(int));
  lseek(fd, -4, SEEK_CUR);
  printf("Read ticket no: %d\n", buffer);
  buffer++;
  lock.l_type=F_WRLCK;
  fcntl(fd, F_SETLKW, &lock);
  printf("Write lock set\n");
  write(fd, &buffer, sizeof(int));
  lseek(fd, -4, SEEK_CUR);
  read(fd, &buffer, sizeof(int));
  printf("Read after writing: %d\n", buffer);
  printf("Press return to unlock...");
  getchar();
  lock.l_type=F_UNLCK;
  fcntl(fd, F_SETLKW, &lock);
  close(fd);
  return 0;
}
