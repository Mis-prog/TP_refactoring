#include "PrimesGenerator.h"

void PrimesGenerator::set(bool* f, int s)
{
    // инициализировать массив значениями true
    for (int i = 0; i < s; i++)
        f[i] = true;
    // избавиться от известных не простых чисел
    f[0] = f[1] = false;
}

std::vector<int> PrimesGenerator::generatePrimes(int maxValue)
{
  if (maxValue >= 2) // единственный допустимый случай
  {
    // объявления
    int s = maxValue + 1; // размер массива
    bool* f = new bool[s];
    int i;
    set(f, s);
    // решето
    int j;
    for (i = 2; i < sqrt(s) + 1; i++)
    {
      if (f[i]) // если i не вычеркнуто, вычеркнуть кратные ему числа
      {
        for (j = 2 * i; j < s; j += i)
          f[j] = false;  // кратное число не является простым
      }
    }
    // сколько есть простых чисел?
    int count = 0;
    for (i = 0; i < s; i++)
    {
      if (f[i])
        count++; // увеличить счетчик
    }
    std::vector<int> primes(count);
    for (i = 0, j = 0; i < s; i++)
    {
      if (f[i]) // если число простое
        primes[j++] = i;
    }
    return primes; // возвратить простые числа
  }
  else // maxValue < 2
    return std::vector<int>(0); // возвратить пустой массив, 
                                // если входные данные некорректны
}
