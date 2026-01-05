#include <stdio.h>
#include "prototypes-headers.h"

//float my_func(int);

int main(void){
    int b=2;
    printf("y=%f\n",my_func(b));
}

float my_func(int b){
    return b+1;
}


