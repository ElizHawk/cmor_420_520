#include <iostream>
#include <cstdio>

class container{
    public:
    // initialize member methods belonging to this class
    // these are acessible outside of the class
    void SetValue(int x);
    int GetValue(void);

    private:
    // this is not acessible (directly) like in previous examples
    //this is acessible to the member methods inside this class
    int value_;
};

void container::SetValue(int x){
    value_=x;
}

int container::GetValue(void){
    return value_;
}

int main(void){
    container x;
    x.SetValue(12);
    // you cannto do: x.value_ because this is a private member
    std::cout<<"Value is "<<x.GetValue() <<std::endl;
}