#include <iostream>
#include <cstdio>

typedef struct{
    int n;
} Mystruct;

Mystruct doubleInput(const Mystruct& input){
    Mystruct doubled;
    doubled.n=2*input.n;
    return doubled;
}

int main(void){
    Mystruct instance={12};
    Mystruct doubled=doubleInput(instance);
    std::cout<<"The given value "<< instance.n <<" doubled is "<<doubled.n<<std::endl;
}