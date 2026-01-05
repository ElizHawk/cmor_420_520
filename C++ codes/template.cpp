#include <iostream>

//template <typename T> : tells comiler its a template
// <typename T> : typename is the return type : int, double, float. 
// Replaces any other 'T' with int, double, float
// add : the templates name
template <typename T> T add(T a, T b){
    return a+b;
}

int main(void){
    int int_val=add<int>(2,3);
    std::cout<< "2+3="<<int_val<<std::endl;

    double dbl_val=add<double>(2.1,3.4);
    std::cout<< "2.1+3.4="<<dbl_val<<std::endl;

}