#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

  char *s = "abdefghjklmnop";
  // int v = {1, 2, 3};

  // [1,0,0,0],[2,0,0,0],[3,0,0,0];


  char *buf = malloc(20);
  if(buf == NULL){
    perror("malloc");
    exit(-1);
  }
  strcpy(s, buf);
  free(buf);

  return 0;
}