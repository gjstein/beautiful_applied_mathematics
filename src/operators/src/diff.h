#include <functional>
#include <vector>

#define EPS 1.0e-8

// Simple derivative
double diff(std::function<double(double)> f, double y);
std::function<double(double)> diff_f(std::function<double(double)> f);
