#include <stdio.h>

int main(void){
    int x=1;
    float y=1.5;

    int* ptr = &x;
    float* ptr=(float *) ptr;
    ptr = &y;

    printf("ptr = %d", *ptr);
}