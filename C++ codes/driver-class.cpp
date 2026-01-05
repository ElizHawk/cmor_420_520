#include "classA.h"
#include "classB.h"

int main(void){
    A a;
    B b;
    b.ptr_a=&a;
    a.ptr_b=&b;
}