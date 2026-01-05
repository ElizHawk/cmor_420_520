#include <iostream>
#include <cstdio>

class Vector{
    public:
    // initialize int, double, etc data types in a class
    int length_;
    double* vals_;
};

int main(void){
    Vector vec;
    vec.length_=3;

    double i=5.0;
    double j=5.1;
    vec.vals_=&i;
    vec.vals_=&j;
}