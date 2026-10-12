#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
// #include <.h>

extern char **environ;
//char *argv[] == char **argv;

int main(){
    char **e = environ;

    // //for (char **ep = environ; *ep != NULL; ep++){
    // for (int i=0; e[i] !=NULL; i++){
    // //puts(*ep);
    // prinf("%s\n", e[i]);
    // }

    char* path = getenv("PATH");
    printf("%s\n", path);

    putenv("PATH2=/ee3233");
    char* path2 = getenv("PATH2");
    char* path3 = getenv("PATH3");
    if(path3 != NULL){
        printf("%s\n", path3);
    }

    printf("%s\n", path2);

    exit(EXIT_SUCCESS);

    return 0;
}
