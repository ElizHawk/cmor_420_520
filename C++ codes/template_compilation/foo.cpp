#include "foo.hpp"
#include <iostream>

template <typename T> void foo(T x){
    std::cout<< "running foo"<<std::endl;
}

//template void foo<int>(int x);