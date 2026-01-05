#include <stdio.h>

int main(void){
    int* ptr;
    printf("Initially: ptr=%p, value=%d\n,ptr, *ptr");
    int i=12;
    ptr=&i;
    printf("Next: ptr=%p, value=%d\n", ptr,*ptr);
    ptr=NULL;
    printf("Next: ptr=%p, value=(cannot access)\n", ptr);

}