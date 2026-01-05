#include <iostream>

using namespace std;

class A {
 public:
  A(void){
    cout << "In A's constructor\n";
  }
  A(int){
    cout << "In A's `int` constructor\n";
  }
  ~A(){
    cout << "In A's destructor\n";
  }
};

class B {
 public:
  B(void) : a() {
    cout << "In B's 1st constructor\n";
  }
  B(int) : a(1) {
    cout << "In B's 2nd constructor\n";
  }
  ~B(){
    cout << "In B's destructor\n";
  }
  A a;
};

int main(void) {
  
  //  B* ptr_a = new B;
  //  B* ptr_b = new B(3);
  B* ptr_c = new B[3];
  delete[] ptr_c; 
 
}
