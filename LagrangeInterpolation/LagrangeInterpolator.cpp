#include "LagrangeInterpolator.h"

using namespace std;

std::vector<double> LagrangeInterpolator::interpolate_array(
  std::vector<double> xs, // точки, в которых функци€ известна
  std::vector<double> fs, // известные значени€ функции
  std::vector<double> xs_calc  // точки, в которых нужно посчитать 
  // значение интерпол€ционного многочлена Ћагранжа
)
{
  vector <double> fs_calc(xs_calc.size());
  for (int i = 0; i < xs_calc.size(); i++)
  {
    int s = 0; // обща€ сумма многгочлена
    for (int j = 0; j < xs.size(); j++)
    {
      int mult_xs = fs[j]; //отдельный множитель дл€ xs[i]
      for (int k = 0; k < xs.size(); k++)
        if (k != j)
          mult_xs *= (xs_calc[i] - xs[k]) / (xs[j] - xs[k]);
      s += mult_xs;
    }
    fs_calc[i] = s;
  }
  return fs_calc;
}

