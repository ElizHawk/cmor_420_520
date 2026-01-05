#include <stdio.h>
#include <stdlib.h>

int * foo(void){
  int x = 1; // stack memory: unallocated at the end of "foo"
  return &x;
}

int main(void){

  int * ptr = foo(); // return pointer to stack memory

  // reference old pointer to stack memory
  printf("*ptr = %d\n", *ptr); 
}
