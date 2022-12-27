#include "PrimesGenerator.h"

void PrimesGenerator::set(bool* f, int s)
{
    // ���������������� ������ ���������� true
    for (int i = 0; i < s; i++)
        f[i] = true;
    // ���������� �� ��������� �� ������� �����
    f[0] = f[1] = false;
}

void PrimesGenerator::metod(bool* f, int s)
{
    for (int i = 2; i < sqrt(s) + 1; i++)
    {
        if (f[i]) // ���� i �� ����������, ���������� ������� ��� �����
        {
            for (int j = 2 * i; j < s; j += i)
                f[j] = false;  // ������� ����� �� �������� �������
        }
    }
}

int PrimesGenerator::count(bool* f, int s)
{
    int count = 0;
    for (int i = 0; i < s; i++)
    {
        if (f[i])
            count++; // ��������� �������
    }
    return count;
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
    metod(f, s);
    // ������� ���� ������� �����?
    std::vector<int> primes(count(f,s));
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
