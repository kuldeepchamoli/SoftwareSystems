/*
================================================
Author : Kuldeep Chamoli

Description :
Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int fd = open("/home/kuldeep-chamoli/Desktop/SoftwareSystems101-main/q8/file_read.txt", O_RDONLY);
	if(fd == -1) {
		perror("Failed to open file!");
		return 1;
	}

	// read 1 char to encounter end of line character
	char buff;
	int numberOfBytesRead = read(fd, &buff, 1);

	printf("Press \"enter\" to read next line. \n\n");

	while(numberOfBytesRead > 0) {
		if(buff == '\n')
			getchar();
		else
			printf("%c", buff);
		numberOfBytesRead = read(fd, &buff, 1);
	}

	if(numberOfBytesRead == -1) {
		perror("Failed to read file!");
		return 1;
	}

	return 0;
}
