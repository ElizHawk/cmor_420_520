#include <iostream>

using namespace std;

template <typename Type>
class Wrapper{
public:
  Type get_value(); 
  void set_value(Type value){
    this -> value = value;
  };
private:
  Type value;
};



int main(void) {
  Wrapper<int> foo;
  foo.set_value(1);
  cout << "foo.value is ";
  cout << foo.get_value() << endl;
}
