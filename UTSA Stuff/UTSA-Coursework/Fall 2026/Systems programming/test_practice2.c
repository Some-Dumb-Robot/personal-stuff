#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>


int main(int argc, char *argv[]){

    if (argc != 3) {
        char erd[] = "wrong argument count\n";
        write(2, erd, sizeof(erd) - 1);
        return -1;
    }


    char *genv = getenv(argv[1]);
    if(genv == NULL){
        char erd[] = "No environement variable\n";
        write(2, erd, sizeof(erd) - 1);
                return -1;

    }

    int chubby = write(1, genv, strlen(genv));
    if (chubby == -1){
        char erd[] = "failed write to terminal\n";
        write(2, erd, sizeof(erd) - 1);
                return -1;

    }

    int chibby = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (chibby == -1){
        char erd[] = "failed open\n";
        write(2, erd, sizeof(erd) - 1);
                return -1;

    }

    int written = write(chibby, genv, strlen(genv));
    if (written == -1){
        char erd[] = "failed write to file\n";
        write(2, erd, sizeof(erd) - 1);
                return -1;

    }



    return 0;
}