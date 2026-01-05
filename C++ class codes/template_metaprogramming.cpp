#include <iostream>

using namespace std;

// a common example of template metaprogramming
// factorial(n) = n * (n-1) * (n-2) ... * 1
//              = n * factorial(n-1)
// factorial(0) = 1 

template <int n> struct Factorial{
  const static int result =
    n * Factorial<n-1>::result;
};

// specialization on n=0
template <> struct Factorial<0>{
  const static int result = 1;
};

int main(void) {
  int n = Factorial<4>::result;
  cout << "n = " << n << endl;    
}

