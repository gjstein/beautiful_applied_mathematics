#include "diff.h"

double diff(std::function<double(double)>f, double y) {
  return ( f(y+EPS) - f(y-EPS) )/( 2.0*EPS );
}
std::function<double(double)> diff_f(std::function<double(double)>f){
  using namespace std::placeholders;
  return std::bind(diff,f,_1);
}
