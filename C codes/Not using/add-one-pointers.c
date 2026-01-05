#include <stdio.h>

void add_one(int* x,double* y){
    //int& xx=x;
    (*x)++;
    *y = *y+1;
     
    //return (x,y);
}

int main(void){
    int a=2;
    double b=3.0;
    printf("At the beginning: a=%d, b=%f\n", a,b);
    add_one(&a,&b);
    printf("At the end: a=%d, b=%f\n", a,b);
    
}