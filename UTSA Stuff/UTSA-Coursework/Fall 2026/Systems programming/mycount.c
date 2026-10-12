#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    char buf[4092];
    int bTotal = 0;
    int aTotal = 0;

    if(argc < 2){
        char errd[] = "./mycount <file>";
        write(2, errd, sizeof(errd));
        exit(1);
    }
    for(int i; i < (argc - 1); i++){
        int fd = 0;
        int counter = 0;
        fd = open(argv[i + 1], O_RDWR, S_IRUSR | S_IWUSR);
        if(fd == -1){
            perror("failed open");
            exit(1);
        }

        int readFile = read(fd, buf, sizeof(buf) - 1);
        if(readFile == -1){
            perror("failed read");
            exit(1);
        }

        for(int j = 0; j < strlen(buf); j++){
            if(buf[j] == '\n'){
                counter++;
            }
        }

        sprintf(buf,"%7ld lines, %7ld bytes, %s\n", (long)counter, (long)readFile, argv[i+1]);
        write(1, buf, strlen(buf));
        bTotal += readFile;
        aTotal += counter;
        

        char buf2[4096];
        write(1, buf2, strlen(buf2));
        close(fd);
    }

    char buf3[4096];
    
    sprintf(buf3,"%7ld lines, %7ld bytes, total \n", (long)aTotal, (long)bTotal);
    write(1, buf3, strlen(buf3));

    
    return 0;
}