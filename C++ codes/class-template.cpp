#include <iostream>

// template with return type (int double float) T
// class template
template <typename T> class wrapper{
    public:
    T getvalue(void){return value;}
    void setvalue(T x){value=x;}

    private:
    T value;
};

int main(void){
    wrapper<int> wrap;
    wrap.setvalue(3);
    std::cout<<"value is "<< wrap.getvalue()<<std::endl;
}