#include <stdio.h>
#include <stdlib.h>

int greater_than(int * x, int * y){
  return *x > *y;
}

int less_than(int * x, int * y){
  return *x < *y;
}

// note: parentheses matter. "int* compare(...)"
// and "int (*compare)(...)" are different.
void compare_vectors(int *out, int n, int * x, int * y,
		     int (*compare)(int *, int *)){
  for (int i = 0; i < n; ++i){
    out[i] = (*compare)(&x[i], &y[i]);
  }
}

int main(void){
  int x[] = {1, 2, 3}; 
  int y[] = {2, 1, 3}; 
  int out[3];
  compare_vectors(out, 3, x, y, &less_than);
  for (int i = 0; i < 3; ++i){
    printf("compare(%d, %d) = %d\n", x[i], y[i], out[i]);
  }
}
