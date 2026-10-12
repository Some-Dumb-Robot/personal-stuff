#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
// #include <.h>

int main(){

    char buf[10];
    // int open(const char *path, int flags, ... /* mode_t mode +/);*/) 

    int fd = open("hello.txt", O_WRONLY|O_CREAT);
    if (-1 == fd){
        perror("open");
        return -1;
    }
    close(fd);


    printf("buf contents: %s\n", buf);

    int fd2 = open("hello_copy.txt", O_WRONLY|O_CREAT|O_TRUNC );
    if(-1 ==fd2){
        perror("open");
        return -1;
    }

    int num_written = write(fd2, buf, strlen(buf));
    if (num_written == -1){
        perror("write");
        close(fd2);
        return -1;
    }

    close(fd2);


    return 0;
}
