#include "diff.h"

double diff(std::function<double(double)>f, double y) {
  return ( f(y+EPS) - f(y-EPS) )/( 2.0*EPS );
}
std::function<double(double)> diff_f(std::function<double(double)>f){
  return [=](double y){ return diff(f,y);};
}

// Function which computes the gradient vector
dvec grad(dvfun f, dvec y)
{
  // Dimension of y/output
  int dim = y.size();
  
  // Initialize output vector
  dvec out(dim);
  dvec y_delta(y);
  
  // Loop through elements of y
  for(int qqq=0; qqq<dim; qqq++)
  {
    // Initialize output
    out[qqq] = 0;
    // +delta contribution
    y_delta[qqq] = y[qqq] + EPS;
    out[qqq] += +f(y_delta)/( 2.0*EPS );
    // -delta contribution
    y_delta[qqq] = y[qqq] - EPS;
    out[qqq] += -f(y_delta)/( 2.0*EPS );
    // reset offset
    y_delta[qqq] = y[qqq];
  }

  return out;
  
}

vvfun grad_fun(dvfun f){ return [=](dvec y){ return grad(f,y); }; }
