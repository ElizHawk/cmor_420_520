#include <stdio.h>

int main(void){

  // defining an array and initializing it
  int x[5] = {0, 1, 2, 3, 4};

  // defining an array and filling it after
  int n = 5;
  int y[n];
  for (int i = 0; i < n; ++i){
    y[i] = i + 10;
  }

  for (int i = 0; i < n; ++i){
    printf("x[%d] = %d, y[%d] = %d\n", i, x[i], i, y[i]);
  }

  printf("x = %d\n", x);

}
