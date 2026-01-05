#include <stdio.h>

int main(void){
    int my_int; // Declare an int
    int* ptr_int; // Declare a pointer to an int

    my_int=2; // Initialize an int
    ptr_int= &my_int; // Initializa a int pointer to address of my_int

    
    
    int a=2;
    int b=3;
    printf("At the beginning: a=%d, b=%d\n", a,b);

    ptr_int=&a; // Initializes pointer with the address to a
    b=*ptr_int; // acesses the contents of the pointers address (and copies to b)
    printf("At the next step: a=%d, b=%d\n", a,b);

    *ptr_int=4; // acesses the contents of the pointers address (and changes it)
     printf("At the end: a=%d, b=%d\n", a,b);


}