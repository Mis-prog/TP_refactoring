#include <iostream>
#include <vector>
#include "LagrangeInterpolator.h"

using namespace std;

int main()
{
  int n = 0, n_calc;
  cout << "Input count of initial points\n";
  cin >> n;
  vector <double> x(n), f(n);
  cout << "Input points as column of pairs x f(x)\n";
  for (int i = 0; i < n; i++)
    cin >> x[i] >> f[i];

  cout << "Input count of calculated points\n";
  cin >> n_calc;
  cout << "Input x for calculation of interpolated function\n";
  vector <double> x_calc(n_calc);
  for (int i = 0; i < n_calc; i++)
    cin >> x_calc[i];
  vector <double> f_calc = LagrangeInterpolator::interpolate_array(x, f, x_calc);
  cout << "Result:\n";
  for (int i = 0; i < n_calc; i++)
    cout << x_calc[i] << " " << f_calc[i] << endl;

  return 0;
}
