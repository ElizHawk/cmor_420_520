#include <stdio.h>
#include <limits.h> // max/min values of different data types
#include <float.h> // info about floating point standards

int main(void){

  // C is simple: 4 data types in C
  int x = 1;
  float y = 1.0; // single precision
  double z = 1.0; // double precision
  char cc = 'a';

  // short + long modifier
  short int a; 
  long int b;
  long c; // same as long int
  long double d; // 128-bit (quad precision)
  
  printf("size of int = %lu\n", sizeof(int));
  printf("size of float = %lu\n", sizeof(float));
  printf("size of double = %lu\n", sizeof(double));
  printf("size of char = %lu\n", sizeof(char));
  printf("size of long int = %lu\n", sizeof(long int));
  printf("size of long double = %lu\n", sizeof(long double));

  printf("Max value of unsigned int = %u\n", UINT_MAX);
  printf("Max value of unsigned long int = %lu\n", ULONG_MAX);
  printf("Max value of float = %g\n", FLT_MAX);
  printf("Max value of double = %g\n", DBL_MAX);   
}
