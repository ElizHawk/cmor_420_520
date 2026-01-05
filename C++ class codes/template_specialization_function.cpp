#include <iostream>
using namespace std;

template <typename T, int n> void foo() {
  cout << "Running foo (no specialization)\n";
  cout << "n = " << n << endl;
}

template <> void foo<int, 0>() {
  cout << "Running foo<int, 0>\n";
}

int main(void) {
  foo<double, 1>();
  foo<int, 0>();
}
