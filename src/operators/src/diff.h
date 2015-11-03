#include <functional>
#include <vector>

#define EPS 1.0e-8

typedef std::vector<double> dvec;
typedef std::function<double(dvec)> dvfun;
typedef std::function<dvec(dvec)> vvfun;

// Gradient
dvec grad(dvfun f, dvec y);
vvfun grad_fun(dvfun f);


// Simple derivative
double diff(std::function<double(double)> f, double y);
std::function<double(double)> diff_fun(std::function<double(double)> f);
