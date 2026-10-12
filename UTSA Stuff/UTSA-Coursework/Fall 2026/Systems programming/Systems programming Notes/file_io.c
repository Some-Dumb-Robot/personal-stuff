#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>



int main(){

    int fd = open("hello.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
    if(fd == -1){
        perror("open");
        return -1;
    }

    printf("fd: %d\n", fd);

    ssize_t num_written = write(fd, "hello", 6);
    if (num_written == -1){
        perror("write");
        return -1;
    }

    close(fd);

    int fd2 = open("hello.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
    if(fd2 == -1){
        perror("open");
        return -1;
    }

    printf("fd2: %d\n", fd2);
}