#include "diff.h"

double diff(double (*f)(double x), double y) {
  return ( f(y+EPS) - f(y-EPS) )/( 2.0*EPS );
}
