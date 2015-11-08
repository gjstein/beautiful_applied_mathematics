#pragma once

#include <functional>
#include <vector>

namespace operators {

// Define data structure
class DT {
 public:
  double y;
  double t;
  DT(double y_in, double t_in){
    y = y_in;
    t = t_in;
  };
};


/***********
    RK4
*************/

double rk4(std::function<double(double,double)> ydot, double t, double y, double h);
DT rk4(std::function<double(double,double)> ydot, DT in, double h);

}
