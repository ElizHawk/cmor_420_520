#include <iostream>
using namespace std;

/*
typedef struct{
  int x;
  int y;  
} Foo;
  
void modify_Foo(Foo & foo){
  foo.x = 10;
  foo.y = 20;  
}

int main(void){
  Foo foo = {1, 2};
  modify_Foo(foo);
  cout << "foo.x, foo.y = " <<
    foo.x << ", " << foo.y << endl;
}
*/
int main(void) {
  
  int i;
  int * ptr_i = &i;    
  int & ref_i = i;
  
  cout << "Address of i = " <<
    &i << endl;
  cout << "ptr_i = " <<
    ptr_i << endl;
  cout << "Address of ref_i = " <<
    &ref_i << endl;        
  return 0;
  
  *ptr_i = 6;   
  ref_i = 7;
  cout << "i = " << i << endl;
  cout << "ptr_i = " << (*ptr_i) << endl;
  cout << "ref_i = " << ref_i << endl;
    
}

