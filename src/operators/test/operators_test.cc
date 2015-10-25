#include <functional>
#include <vector>
#include <cmath>

#include "gtest/gtest.h"

#include "diff.h"


// Define functions (to be operated upon)
double f_squared(double x) { return x*x; }


TEST(DiffTest, SimpleFunctionTests) {
  EXPECT_NEAR(2.0, diff(*f_squared,1.0), 1e-8);
}


TEST(DiffTest, BindFunctionTests) {

  // Namespace for std::bind
  using namespace std::placeholders;

  // Variable def
  std::vector<double> v_x(5);
  v_x = {0.1, 1.0, 2.0, 2.718, 10.0};
  
  // Create the bound function
  auto df_squared = std::bind(diff,*f_squared,_1);
  auto df_sqrt = std::bind(diff,*sqrt,_1);

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
