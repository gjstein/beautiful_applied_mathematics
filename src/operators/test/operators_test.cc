#include <functional>
#include <vector>
#include <cmath>

#include "gtest/gtest.h"

#include "diff.h"


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
  auto df_squared = diff_f(f_squared);
  auto df_sqrt = diff_f(sqrt);

  // Loop through x's
  for (double x : v_x )
  {
    // Test bound functions
    ASSERT_NEAR(2*x, df_squared(x), 1e-5);
    ASSERT_NEAR(1/2.0/sqrt(x), df_sqrt(x), 1e-5);
  }
  
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}
