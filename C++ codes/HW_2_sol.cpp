#include <cstdio>
#include <iostream>

#include "HW_2.hpp"


int main(void){
    MyMatrix A(4,3);
    A.set_data(0);

    MyMatrix B(3,4);
    B.set_data(0);

    MyMatrix C(4,3);
    C.set_data(1);

    MyMatrix x(4,1);
    x.set_data(0);

    MyMatrix y(4,1);
    y.set_data(1);

    MyMatrix z(4,1);
    z.set_data(2);

    MyMatrix a(A.rows,1);
    //MyMatrix b(z.rows,1);
    //MyMatrix c(A.rows,1);
    
    a = x;
    a = 2*x;



    
}