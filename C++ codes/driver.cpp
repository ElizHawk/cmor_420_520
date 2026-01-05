#include <iostream>
#include "shape2d.h"

int main(void){
    //shape2d shape;
    //shape.setwidth(3.0);
    //shape.setheight(1.0);

    rectangle rect;
    rect.setwidth(3.0);
    rect.setheight(1.0);
    std::cout<<"rectangle width is "<<rect.getwidth()<<std::endl;
    std::cout<<"rectangle height is "<<rect.getheight()<<std::endl;

    triangle tri(3.0,1.0);
    std::cout<<"traingle width is "<<rect.getwidth()<<std::endl;
    std::cout<<"triangle height is "<<rect.getheight()<<std::endl;

    shape2d* ptr_shape=&rect;
    std::cout<<"first area is "<<ptr_shape->getarea()<<std::endl;
    ptr_shape=&tri;
    std::cout<<"second area is "<<ptr_shape->getarea()<<std::endl;
    
}