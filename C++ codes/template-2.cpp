#include <iostream>

//template <typename T, int N> T add_N(T a){
template <typename T, int N=5> T add_N(T a){
    return a+N;
};

int main(void){
    //double d=add_N<double, 5>(3.1);
    double d=add_N<double>(3.1);
    std::cout<<"5+3.1= "<<d<<std::endl;

    //const int n=5;
    //int i=add_N<int,n>(3);
    int i=add_N<int>(3);
    std::cout<<"5+3= "<<i<<std::endl;
}