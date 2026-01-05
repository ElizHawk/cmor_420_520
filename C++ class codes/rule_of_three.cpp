#include <iostream>
#include <cstdlib>

using namespace std;

class MyClass{
public:
  MyClass();
  MyClass(int);
  ~MyClass();
    
  // the `const` keyword enforces that this
  // function cannot modify this instance.
  int get_value(void) const{ return *ptr_; }
  void set_value(int val){ *ptr_ = val; }
  
private:
  int * ptr_;
};

MyClass::MyClass(){
  ptr_ = (int *) malloc(sizeof(int));
}

MyClass::MyClass(int value){
  ptr_ = (int *) malloc(sizeof(int));
  *ptr_ = value;
}

MyClass::~MyClass(){
  free(ptr_);
  ptr_ = nullptr; // same as NULL 
}  
  
int main(void){
  MyClass x;
  x.set_value(10);
  cout << "x value = " << x.get_value() << "\n";

  MyClass y(20);
  cout << "y value = " << y.get_value() << "\n";

  MyClass z = y;
}
