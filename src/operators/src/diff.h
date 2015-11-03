#include <functional>
#include <vector>

#define EPS 1.0e-8

typedef std::vector<double> dvec;
typedef std::function<double(dvec)> dvfun;
typedef std::function<dvec(dvec)> vvfun;

// Gradient
double grad(std::function<double(double)> f, double y);
dvec grad(std::function<double(dvec)> f, dvec y);


// Simple derivative
double diff(std::function<double(double)> f, double y);
std::function<double(double)> diff_fun(std::function<double(double)> f);


// Lambda Outputs
std::function<double(double)> grad(std::function<double(double)> f);
std::function<dvec(dvec)> grad(std::function<double(dvec)> f);

/*template<typename T, typename U> std::function<T(U)> grad(std::function<T(U)> f)
{
return [=](U y){ return grad(f,y); };
}
    
template<typename T, typename U> std::function<T(U)> grad(T (*f)(U))
{
return [=](U y){ return grad(f,y); };
}
*/
