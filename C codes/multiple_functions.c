#include <stdio.h>
#include <math.h>

int my_func_1(int x) {
  return x + 1;
}

int my_func_2(int x) {
  return pow(x, 2);
}

int main(void) {
    int x = 2;
    printf("The output of" 
      "my_func_2(%d) = %d\n", x, my_func_2(x));
}



