#include "runge_kutta.h"

namespace operators {

double rk4(std::function<double(double,double)> ydot, double t, double y, double h)
{
  double k1 = ydot(t,y);
  double k2 = ydot(t+h/2,y+h*k1/2);
  double k3 = ydot(t+h/2,y+h*k2/2);
  double k4 = ydot(t+h,y+h*k3);

  return y + h/6 * ( k1 + 2*k2 + 2*k3 + k4 );
  
}


DT rk4(std::function<double(double,double)> ydot, DT in, double h)
{

  double k1 = ydot(in.t,in.y);
  double k2 = ydot(in.t+h/2,in.y+h*k1/2);
  double k3 = ydot(in.t+h/2,in.y+h*k2/2);
  double k4 = ydot(in.t+h,in.y+h*k3);

  DT out(in.y + h/6 * ( k1 + 2*k2 + 2*k3 + k4 ) , in.t + h);

  return out;
  
}


} // namespace operators
