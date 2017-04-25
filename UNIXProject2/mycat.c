// -----------------------------------------------------------------
// mycat
// This script outputs the contents of text files
// -----------------------------------------------------------------
#include <stdio.h>    
#include <unistd.h>   
#include <sys/stat.h> 
#include <fcntl.h>
#define TRUE 1
#define FALSE 0
int main(int argc, char **arguments)
{
// must have at least one argument
if(argc < 2)
{
    printf("You must enter at least one argument to use mycat.");
    return 0;
}
int fd;     // file descriptor
int fd2;
int buf;    // buffer
    fd = open(arguments[1], O_RDONLY);
    if (fd < 0) {perror(arguments[1]); return 0; }
    // only one file on the command line
    if(argc == 2)
    {
        while (read(fd, &buf, 1) == 1 ) 
            write(STDOUT_FILENO, &buf, 1);
        close(fd);
    }
    // two files on the command line (redirection of output to the second file)
    else
    {
        fd2 = open(arguments[2], O_RDONLY);
        while (read(fd, &buf, 1) == 1 ) 
            write(fd2, &buf, 1);
        close(fd);  
    }
return 1;
}


