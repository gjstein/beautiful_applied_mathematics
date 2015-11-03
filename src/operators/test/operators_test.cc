#include <cmath>

#include "gtest/gtest.h"

#include "diff.h"
#include "runge_kutta.h"

// Define functions (to be operated upon)
double f_squared(double x) { return x*x; }


TEST(DiffTest, SimpleFunctionTests) {
  EXPECT_NEAR(2.0, diff(*f_squared,1.0), 1e-8);

  // Variable def
  std::vector<double> v_x(5);
  v_x = {0.1, 1.0, 2.0, 2.718, 10.0};

  // Create the functions
  std::function<double(double)> f_sq = f_squared;
  for (double x : v_x)
  {
    // Test function derivatives
    ASSERT_NEAR(2*x, diff(f_sq,x),1e-5);
  }
  
}


TEST(DiffTest, BindFunctionTest) {

  // Namespace for std::bind
  using namespace std::placeholders;

  // Variable def
  std::vector<double> v_x(5);
  v_x = {0.1, 1.0, 2.0, 2.718, 10.0};

  // Create bound function from function pointers
  auto df_squared = diff_fun(f_squared);
  auto df_sqrt = diff_fun(sqrt);

  // Loop through x's
  for (double x : v_x )
  {
    // Test bound functions
    ASSERT_NEAR(2*x, df_squared(x), 1e-5);
    ASSERT_NEAR(1/2.0/sqrt(x), df_sqrt(x), 1e-5);
  }
  
}


TEST(GradTest, SimpleTest) {

  // Initialize position vector
  dvec y = { 1.5, 2.0, 1.34 };

  // Define the function and its gradient
  auto f2d = [=](dvec y) { return y[0]*y[0] + 2.0*y[1]*y[1] + y[2]*y[2]*sqrt(y[2]); };
  auto a_grad_f2d = [=](dvec y){
    dvec out { 2.0*y[0], 2*2.0*y[1], 2.5*y[2]*sqrt(y[2]) };
    return out;
  };
  // Calculate the gradients (both methods)
  dvec analytic_grad = a_grad_f2d(y);
  dvec numerical_grad = grad(f2d,y);
  
  // Loop through elements & compare
  int dim = y.size();
  for (int qqq = 0; qqq<dim; qqq++)
    ASSERT_NEAR(analytic_grad[qqq], numerical_grad[qqq], 1e-5);

}

TEST(RungeKuttaTest, SimpleTest)
{
  // Define the RHS
  auto ydot = [=](double t, double y){ return y; };

  // Initial conditions
  double y = 1.0;
  double t = 0.0;
  double tf = 1.0;
  int num_steps = 20;
  double dt = (tf-t)/num_steps;
  for (int qqq = 0; qqq<num_steps; qqq++){
    // Compute y at t+dt
    y = rk4(ydot,t,y,dt);
    // Update t
    t = t + dt;
    // Test accuracy
    ASSERT_NEAR(y,exp(t),1e-6);
  }
  
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}
