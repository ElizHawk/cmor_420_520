#include <iostream>

using namespace std;

struct Foo{
  explicit Foo(int x){}
};

void bar(Foo foo){
  cout << "calling bar(Foo)\n";
}

int main() {
  bar(42);
}
