class shape2d{
    public:
    shape2d(void){}
    shape2d(double w,double h): width(w), height(h){}
    void setwidth(double w){ width=w;}
    void setheight(double h){height=h;}
    double getwidth(void) const {return width;}
    double getheight(void) const {return height;}
    virtual double getarea(void)=0;

    protected:
    double width=0.0;
    double height=0.0;
};

class rectangle : public shape2d{
    public:
    double getarea(void){ return width*height;}
};

class triangle: public shape2d{
    public:
    triangle(double w, double h): shape2d(w,h){}
    double getarea(void){return .5*width*height;}
};
