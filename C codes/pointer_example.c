#include <stdio.h>

int main(void){

  int a = 2;
  int b = 3;
  printf("At the beginning: a = %d, b = %d\n", a, b);

  int* ptr_int;
  ptr_int = &a; // ptr_int is the address of "a"
  b = *ptr_int; // b dereferences the pointer to get "a"
  *ptr_int = 4; // the memory pointed to by "ptr_int" is set to 4
  printf("At the end: a = %d, b = %d\n", a, b);
  
  return 0;
}
