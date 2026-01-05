#include <iostream>

class A{
    public:
    virtual double getvalue(void){return 1;}
};

class B:public A{
    public:
    double getvalue(void){return 2;}
};

int main(void){
    A* ptr_A;
    B b;
    std::cout<<"getvalue()="<< b.getvalue()<<std::endl;

    ptr_A=&b;

    std::cout<<"getvalue()="<< ptr_A->getvalue()<<std::endl;
}