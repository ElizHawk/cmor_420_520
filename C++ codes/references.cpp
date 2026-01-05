#include <iostream>
#include <cstdio>

int main(void){
    int i;
    int* ptr_i = &i;
    int& ref_i =i;
    i=5;
    std::cout<<"i="<<i<<std::endl;
    
    *ptr_i = 6;
    std::cout<<"i="<<i<<" ptr_i="<<*ptr_i<<std::endl;
    
    ref_i = 7;
    std::cout<<"i="<<i<<" ref_i="<<ref_i<<" ptr_i="<<*ptr_i<<std::endl;
    
}