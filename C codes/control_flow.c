#include <stdio.h>

int main(int argc, char** argv){

  // an if loop example
  if (argc == 1) {
    printf("No arguments.\n");
  } else if (argc == 2){
    printf("One argument.\n");
  }
  else {
    printf("More than one argument.\n");
  }

  // for loop
  int n = 4;
  for (int i = 0; i < n; i++) {
    printf("On iteration %d of %d\n", i, n-1);
  }

  // while loop
  int i = -1;
  while (i < n) {
    i += 1; //i=i+1, ++i, i++
    printf("On iteration %d of %d in while loop\n", i, n-1);
  }

  // do-while
  i = -1;
  do {
    i += 1;
    printf("On iteration %d of %d in do-while loop\n", i, n-1);    
  } while (i < n);

  // break and continue statements
  i =-1;
  while (1) {
    ++i;
    if (i % 2) {
      continue; // exits the current iteration but continues
    }

    printf("On iteration %d out of 10 in while loop\n", i);
    if (i == 10) {
      break; // exits the current iteration and stops
    }
      
  }
  

}
