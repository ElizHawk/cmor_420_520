#include "point.h"

Point compute_average(int num_points, Point * points){
  double x_avg = 0.0;
  double y_avg = 0.0;
  for (int i = 0; i < num_points; ++i){
    Point pt = points[i];
    x_avg += pt.x;
    y_avg += pt.y;
  }
  x_avg /= num_points;
  y_avg /= num_points;
  Point point_avg = {x_avg, y_avg};
  return point_avg;
}

