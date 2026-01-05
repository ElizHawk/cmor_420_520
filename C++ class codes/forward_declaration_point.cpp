#include <iostream>

using namespace std;

class ScaledPoint;

class Point{
public:
  Point(double x, double y){
    this->x = x;
    this->y = y;
  }
  Point & operator+=(Point a);
  Point & operator+=(ScaledPoint a);  
  
  double get_x(){ return x; };
  double get_y(){ return y; };

  
  void print(){
    cout << get_x() << ", " <<
      get_y() << endl;
  }
protected:
  double x;  
  double y;
};

class ScaledPoint : public Point{
public:  
  ScaledPoint(double scaling, Point a) :
    Point(a.get_x(), a.get_y())
  {
    this->scaling = scaling;
  };
private:
  double scaling;
};

Point & Point::operator+=(ScaledPoint a){
  this->x += a.get_x();
  this->y += a.get_y();
  return *this;
}

int main(void){
  Point a(1.0, 2.0);
  ScaledPoint b(2.0, a);
  a += b;
}


