#include "runge_kutta.h"

double rk4(std::function<double(double,double)> ydot, double t, double y, double h)
{
  double k1 = ydot(t,y);
  double k2 = ydot(t+h/2,y+h*k1/2);
  double k3 = ydot(t+h/2,y+h*k2/2);
  double k4 = ydot(t+h,y+h*k3);

  return y + h/6 * ( k1 + 2*k2 + 2*k3 + k4 );
  
}
