#include <unistd.h>
#include <stdio.h>
int main()
{
char path[256],name[256];
printf("Enter the path of softlink:");
scanf("%s",path);
printf("Enter the name of softlink :");
scanf("%s",name);
symlink(path,name);
perror("perror");
}
