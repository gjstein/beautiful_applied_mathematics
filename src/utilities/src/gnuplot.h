#pragma once

#include <stdio.h>
#include <vector>

#define GNUPLOT "gnuplot -persist"

namespace util {

void gnuplot(std::vector<double> y);
//void gnuplot(std::vector<double> x, std::vector<double> y);

} // namespace util

