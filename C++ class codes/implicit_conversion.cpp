#include <iostream>

using namespace std;

int foo(bool x){
  return 0;
}

int foo(string string){
  return 1;
}

int main(){
  int i = foo("hi"); 
  cout << "i = " << i << "\n";
}

