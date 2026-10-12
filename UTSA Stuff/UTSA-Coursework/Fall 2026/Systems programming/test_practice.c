#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int fd;
    char buf[4092];

    for(int i; i < (argc - 1); i++){
        fd = open(argv[i + 1], O_RDWR, S_IRUSR | S_IWUSR);
        if(fd == -1){
            char errd[] = "File not opened";
            write(2, errd, sizeof(errd));
        }

        int readFile = read(fd, buf, sizeof(buf) - 1);
        if(readFile == -1){
            perror("die fucker");
            return -1;
        }

        int written = write(1, buf, readFile);
        if(written == -1){
            perror("die snitch");
            return -1;
        }
    }
    return 0;
}