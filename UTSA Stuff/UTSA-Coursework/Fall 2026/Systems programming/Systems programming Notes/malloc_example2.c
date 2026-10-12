#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(){

    struct __attribute__((packed)) mystruct{
    char c; // bit size of 1
    int i; // bit size of 4
    double f; // bit size of 8
    short s; // bit size of 2
    };

    int size = sizeof(struct mystruct);
    printf("size of mystruct pointer %d\n", size);

    struct mystruct x;
    x.s = 'c';
    x.i = 4;
    x.f = 6.0;
    x.s = 1;
    printf("x.s: %c\n", x.s);

    // struct mystruct *ptr = &x;
    // printf("Pointed thing %c\n", (char*ptr)));
}