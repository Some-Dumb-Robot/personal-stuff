#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv){

    if(argc < 4){
        char errd[] = "./mycount <file>";
        write(2, errd, sizeof(errd));
        exit(1);
    }
        
    int ret = setenv(argv[1], argv[2], 0);
    if(ret == -1){
        perror("setenv fail");
        exit(1);
    }

    char *env_val = getenv(argv[1]);
    char *buf = malloc(1024);

    int count = sprintf(buf, "%s = %s", argv[1], env_val);
    int b_w = write(1, buf, count);
    if(b_w ==-1){
        perror("write fail");
        exit(1);
    }

    int fd = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd==-1){
        perror("open fail");
        exit(1);
    }
    int b_w2 = write(fd, buf, count);
    if(b_w2 ==-1){
        perror("write fail 2");
        exit(1);
    }

    close(fd)

    return 0;
}