#include "PrimesGenerator.h"

void PrimesGenerator::set(bool* f, int s)
{
    // ���������������� ������ ���������� true
    for (int i = 0; i < s; i++)
        f[i] = true;
    // ���������� �� ��������� �� ������� �����
    f[0] = f[1] = false;
}

std::vector<int> PrimesGenerator::generatePrimes(int maxValue)
{
  if (maxValue >= 2) // ������������ ���������� ������
  {
    // ����������
    int s = maxValue + 1; // ������ �������
    bool* f = new bool[s];
    int i;
    set(f, s);
    // ������
    int j;
    for (i = 2; i < sqrt(s) + 1; i++)
    {
      if (f[i]) // ���� i �� ����������, ���������� ������� ��� �����
      {
        for (j = 2 * i; j < s; j += i)
          f[j] = false;  // ������� ����� �� �������� �������
      }
    }
    // ������� ���� ������� �����?
    int count = 0;
    for (i = 0; i < s; i++)
    {
      if (f[i])
        count++; // ��������� �������
    }
    std::vector<int> primes(count);
    for (i = 0, j = 0; i < s; i++)
    {
      if (f[i]) // ���� ����� �������
        primes[j++] = i;
    }
    return primes; // ���������� ������� �����
  }
  else // maxValue < 2
    return std::vector<int>(0); // ���������� ������ ������, 
                                // ���� ������� ������ �����������
}
