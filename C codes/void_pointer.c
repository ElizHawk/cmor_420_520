#include <stdio.h>
#include <stdlib.h>

void increment_int(void * x_in){
  int * x = (int *) x_in;  
  (*x) += 1;
}

void increment_double(void * x_in){
  double * x = (double *) x_in;
  (*x) += 1;
}

int main(void){
  int x = 1;
  double y = 1.0;
  
  void (*function_ptr)(void *) = &increment_int;
  (*function_ptr)(&x);

  function_ptr = &increment_double;
  (*function_ptr)(&y);  

  printf("value of x = %d\n", x);
  printf("value of y = %f\n", y);  
}
