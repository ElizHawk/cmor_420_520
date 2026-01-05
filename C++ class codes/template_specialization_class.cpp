#include <iostream>

using namespace std;

template <typename T, int n=1> class Foo{
public:
  Foo() {
    cout << "Foo(): full specialization\n";
  }
  void print(){
    cout << "Fully specialized printing\n";
  }  
};

template <typename T> class Foo<T, 0> {
 public:
  Foo(){
    cout << "Foo(): partial specialization\n";
  }
  void print(); 
};

template <typename T> void Foo<T, 0>::print(){
  cout << "Partially specialized printing\n";
}

int main(void) {
  Foo<double, 1> x;
  x.print();
  Foo<double, 0> y;
  y.print();
}
