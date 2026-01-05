#include <iostream>
using namespace std;

int foo(int x, int y){
  return x + y;
}
int foo(int x, double y){
  return (int) (x + 2.0 * y);
}
int foo(int x, double y, int z){
  return (int) (x + 3.0 * y + z);
}

int main(void){
  cout << "foo(1, 1) = " <<
    foo(1, 1) << endl;
  cout << "foo(1, 1.0) = " <<
    foo(1, 1.0) << endl;
  cout << "foo(1, 1.0, 1) = " <<
    foo(1, 1.0, 1) << endl;
}
