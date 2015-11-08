#include <cmath>

#include "gtest/gtest.h"

#include "operators/diff.h"
#include "operators/runge_kutta.h"

TEST(GradTest, simpleFunctionTests) {

  // Variable def
  std::vector<double> v_x(5);
  v_x = {0.1, 1.0, 2.0, 2.718, 10.0};

  // Create the functions
  std::function<double(double)> f_squared = [](double x){ return x*x; };
  
  for (double x : v_x)
  {
    // Test function derivatives
    ASSERT_NEAR(2*x, operators::grad(f_squared,x),1e-5);
  }
  
}


TEST(DiffTest, lambdaFunctionTest) {

  // Variable def
  std::vector<double> v_x(5);
  v_x = {0.1, 1.0, 2.0, 2.718, 10.0};

  // Function definition
  std::function<double(double)> f_squared = [](double x){ return x*x; };
  
  // Create bound function from function pointers
  auto df_squared = operators::grad(f_squared);
  auto df_sqrt = operators::grad(sqrt);

  // Loop through x's
  for (double x : v_x )
  {
    // Test bound functions
    ASSERT_NEAR(2*x, df_squared(x), 1e-5);
    ASSERT_NEAR(1/2.0/sqrt(x), df_sqrt(x), 1e-5);
  }
  
}


TEST(GradTest, simpleMultidimensionalTest) {

  // Initialize position vector
  std::vector<double> y = { 1.5, 2.0, 1.34 };

  // Define the function and its gradient
  auto f2d = [=](std::vector<double> y) { return y[0]*y[0] + 2.0*y[1]*y[1] + y[2]*y[2]*sqrt(y[2]); };
  auto a_grad_f2d = [=](std::vector<double> y){
    std::vector<double> out { 2.0*y[0], 2*2.0*y[1], 2.5*y[2]*sqrt(y[2]) };
    return out;
  };
  // Calculate the gradients (both methods)
  auto analytic_grad = a_grad_f2d(y);
  auto numerical_grad = operators::grad(f2d,y);
  
  // Loop through elements & compare
  int dim = y.size();
  for (int qqq = 0; qqq<dim; qqq++)
    ASSERT_NEAR(analytic_grad[qqq], numerical_grad[qqq], 1e-5);

  // Test that the bound function is working correctly
  auto lambda_grad = operators::grad(f2d);
  numerical_grad = lambda_grad(y);
  for (int qqq = 0; qqq<dim; qqq++)
    ASSERT_NEAR(analytic_grad[qqq], numerical_grad[qqq], 1e-5);
  
}

TEST(RungeKuttaTest, simpleODEs)
{

  // Declarations
  double y, t, tf, dt;
  int num_steps;
  
  // === Exponential ===
  // y' = y && y(0)=1
      
  // Define the RHS
  auto ydot_exp = [](double t, double y){ return y; };
  // Initial conditions
  y = 1.0;
  t = 0.0; tf = 1.0;
  num_steps = 20; dt = (tf-t)/num_steps;
  // Iterate
  for (int qqq = 0; qqq<num_steps; qqq++){
    // Compute y at t+dt
    y = operators::rk4(ydot_exp,t,y,dt);
    // Update t
    t = t + dt;
    // Test accuracy
    ASSERT_NEAR(y,exp(t),1e-6);
  }

  // === Driven Oscilator ===
  // y' = -sin(t) &&  [y=cos(t)]
  
  // Define RHS
  auto ydot_sin = [](double t, double y){ return -sin(t); };
  // Initial Conditions
  y = 1.0;
  t = 0.0; tf = 1.0;
  num_steps = 20;
  // Iterate
  for (int qqq = 0; qqq<num_steps; qqq++){
    // Compute y at t+dt
    y = operators::rk4(ydot_sin,t,y,dt);
    // Update t
    t = t + dt;
    // Test accuracy
    ASSERT_NEAR(y,cos(t),1e-8);
  }
  
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}
