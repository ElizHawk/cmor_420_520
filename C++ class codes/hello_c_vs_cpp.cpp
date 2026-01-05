#include <cstdio> // can also use <stdio.h>
#include <iostream>

int main(void) {
  printf("In C++, you can use printf like in C...\n");
  std::cout << "...or use the new streaming operator syntax." << std::endl;

  // create an array for 10 ints; explicitly case the malloc output
  int * x = (int *) malloc(sizeof(int) * 10);

  
}
