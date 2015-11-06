#include <functional>
#include <vector>

/***********
    RK4
*************/

double rk4(std::function<double(double,double)> ydot, double t, double y, double h);