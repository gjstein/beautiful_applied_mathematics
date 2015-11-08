#pragma once

#include <functional>
#include <vector>

#define EPS 1.0e-8

namespace operators {

typedef std::vector<double> dvec;
typedef std::function<double(dvec)> dvfun;
typedef std::function<dvec(dvec)> vvfun;

// ==== Gradient ====
// Double -> Double (Simple Derivative)
double grad(std::function<double(double)> f, double y);
std::function<double(double)> grad(std::function<double(double)> f);
// Vector -> Double (Gradient)
dvec grad(std::function<double(dvec)> f, dvec y);
std::function<dvec(dvec)> grad(std::function<double(dvec)> f);


// Simple derivative
double diff(std::function<double(double)> f, double y);
std::function<double(double)> diff_fun(std::function<double(double)> f);

} // namespace operators
