#include <iostream>

using namespace std;

template <typename T> T add(T a, T b) {  
  return a + b;
}

int main(void) {
  int int_val = add<int>(2, 3);
  cout << "2 + 3 = " << int_val << endl;
  
  double dbl_val = add<double>(2.1, 3.0);
  cout << "2.1 + 3.0 = " << dbl_val << endl;

  // this converts from int to double implicitly
  dbl_val = add<double>(2, 3.5); 
  cout << "2 + 3.5 = " << dbl_val << endl;
 
}
