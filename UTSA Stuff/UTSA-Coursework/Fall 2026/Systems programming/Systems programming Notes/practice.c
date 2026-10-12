#include <stdio.h>

int a[5] = {10, 20, 30, 40, 50};
int *p = a;

int main(){


    printf("1 %d\n", p[3]);
    printf("2 %d\n", *(p+2));
    printf("3 %d\n", *p+2);
    printf("4 %d\n", p+2);
    printf("5 %d\n", &a[4] - p);
    printf("6 %d\n", sizeof(a));
    printf("7 %d\n", sizeof(p));

    // printf("%d\n", sizeof(a)/sizeof(a[0]));

    // char s1[] = "goblin";
    // char *s2 = "goblin";
    // char s3[6];
  //  strcpy(s3, s1); // causes an error because s3 is not large enough to hold the string and the null terminator
    // printf("%d\n", sizeof(s1));
    // printf("%d\n", strlen(s1));  // causes error because strlen is not declared in this scope
    // printf("%d\n", sizeof(s2));
    // char s2[0] = "G";

    

    return 0;
}
