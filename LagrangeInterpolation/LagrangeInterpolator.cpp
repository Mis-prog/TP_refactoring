#include "LagrangeInterpolator.h"

using namespace std;

std::vector<double> LagrangeInterpolator::interpolate_array(
  std::vector<double> xs, // �����, � ������� ������� ��������
  std::vector<double> fs, // ��������� �������� �������
  std::vector<double> xs_calc  // �����, � ������� ����� ��������� 
  // �������� ����������������� ���������� ��������
)
{
  vector <double> fs_calc(xs_calc.size());
  for (int i = 0; i < xs_calc.size(); i++)
  {
    int s = 0; // ����� ����� �����������
    for (int j = 0; j < xs.size(); j++)
    {
      int mult_xs = fs[j]; //��������� ��������� ��� xs[i]
      for (int k = 0; k < xs.size(); k++)
        if (k != j)
          mult_xs *= (xs_calc[i] - xs[k]) / (xs[j] - xs[k]);
      s += mult_xs;
    }
    fs_calc[i] = s;
  }
  return fs_calc;
}

