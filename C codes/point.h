#ifndef __POINT__
#define __POINT__

typedef struct{
  double x;
  double y;  
} Point;

#endif

Point compute_average(int num_points, Point * points);

