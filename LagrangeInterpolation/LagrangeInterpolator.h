#pragma once
#include <vector>
class LagrangeInterpolator
{
public:
  static std::vector<double> interpolate_array(
    std::vector<double> x,
    std::vector<double> f,
    std::vector<double> x_calc
  );
};

