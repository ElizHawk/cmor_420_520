#include <iostream>

using namespace std;

class Point{
public:
  Point(double x, double y){
    this->x = x;
    this->y = y;
  }
  double get_x(){ return x; };
  double get_y(){ return y; };

  Point & operator+=(Point a);
  double & operator[](int index);
  
  void print(){
    cout << get_x() << ", " << get_y() << endl;
  }
private:
  double x;  
  double y;
};

Point & Point::operator+=(Point a){
  this->x += a.get_x();
  this->y += a.get_y();    
  return * this;
}

Point operator+(Point a, Point b){
  return a += b;
};

Point operator-(Point a, Point b){
  return Point(a.get_x() - b.get_x(),
	       a.get_y() - b.get_y());
};

Point operator*(double a, Point b){
  return Point(a * b.get_x(),
	       a * b.get_y());
};

Point operator*(Point b, double a){
  return Point(a * b.get_x(),
	       a * b.get_y());
};

double & Point::operator[](int index){
  if (index==0){
    return this->x;
  }else if (index==1){
    return this->y;
  }else{
    // this can be done better...
    cout << "Error: accessing "
      "beyond index 2\n";
  }
}

int main(void){
  Point a(1.0, 2.0);
  Point b(2.0, 3.0);
  a += b;
  a.print();

  a[0] = 13;
  a.print();
}


