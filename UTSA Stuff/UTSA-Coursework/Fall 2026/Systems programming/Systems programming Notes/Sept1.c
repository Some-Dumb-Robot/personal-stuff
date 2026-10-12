#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int a[5] = {10, 20, 30, 40, 50};
int *p = a;


// // will have memory issues because buf is a local variable and will be destroyed when the function returns
// char *make_greeting(const char *name, int num) {
//     //static char buf[64];// can make buf global to fix the function or make it static so it exists after the function
//     char *buf = malloc(strlen(name) + 100); //This also works by putting memory on the heap. Will need to be freed later 
//     snprintf(buf, sizeof(buf), "Hello, %s!, %d!", name, num);
//     printf("%s\n", buf); 
//     return buf; //would be fine if didn't return buf
//   };

// const goes into read only memory and can't be changed
// static exists for the duration of the program and is initialized once
// malloc will allocate memory onto the heap, but needs to be freed up once finished. Will become a memory leak if not freed.



int main(){

    // char *name = "Ivan";
    // int num = 21;
    // char *ret = make_greeting(name, num);
    // printf("%s \n",ret);
    // free(ret);

    return 0;
}
