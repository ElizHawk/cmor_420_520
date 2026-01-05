#include <stdio.h>

int x_global=12;

extern int x_global_init;

int fn_b(int x);

int fn_a(int x,int y){
    return x+y;
}

int main(void){
    printf("Hello, world!\n");
    return fn_b(1);
}