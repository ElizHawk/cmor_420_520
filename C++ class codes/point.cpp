#include <iostream>

using namespace std;

class Point{
public:
  void set_coords(double x,
		  double y){
    x = x;
    y = y;
  }  
  // custom constructor
  Point(){
    x = 0.0;
    y = 0.0;
  }
  // custom destructor
  ~Point(){
    cout << "calling the "
      "custom destructor\n";
  }

private:
  double x;  
  double y; 
};

/*  void print_coords(){
    cout << "(x, y) = " << x;
    cout << ", " << y << "\n";
  }
*/

int main(void){
  Point point;
  point.print_coords();
}
