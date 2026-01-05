#include <stdio.h>

int main(void){
    int x=1;
    int y=1;

    const int* ptr= &x;
    //*ptr = 2;
    ptr =&y;

    printf("ptr = %d\n", *ptr);

    const int* z = malloc(sizeof(int)*10);
    //z[0]=10; 



}