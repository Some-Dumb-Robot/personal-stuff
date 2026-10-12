#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  /*
   * Char example for malloc
   */
  // Hello World is 11 bites of space

  char *a = malloc((11 + 1) * sizeof(char));
  if (a == NULL) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }

  // a[0] = 'H';
  // a[1] = '\0';
  // OR

  strcpy(a, "Hello World");

  printf("%s\n", a);
  free(a);

  /*
   * int example for malloc
   */
  // 1 2 3 4 5
  int *b = malloc(5 * sizeof(int));
  b[0] = 1;
  b[1] = 2;
  b[2] = 3;
  b[3] = 4;
  b[4] = 5;

  for (int i = 0; i < 5; i++) {
    printf("%d ", b[i]);
  }
  free(b);

  /*
   * Char example for malloc
   */



    // calloc allocates memory for an array of num elements of size bytes each and returns a pointer to the allocated memory.
    // void *calloc(size_t num, size_t size); 

    /* realloc changes the size of the memory block pointed to by ptr to size bytes.
     The contents will be unchanged in the range from the start of the region up to the minimum of the old and new sizes.
      If the new size is larger than the old size, the added memory will not be initialized. 
      If ptr is NULL, then the call is equivalent to malloc(size), for all values of size; if size is equal to zero,
       and ptr is not NULL, then the call is equivalent to free(ptr). Unless ptr is NULL,
        it must have been returned by an earlier call to malloc(), calloc() or realloc(). 
        If the area pointed to was moved, a free(ptr) is done. */
    
        // void *realloc(void *ptr, size_t size);
  

  return 0;
}