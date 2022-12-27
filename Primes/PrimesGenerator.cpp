#include "PrimesGenerator.h"

void PrimesGenerator::set(bool* f, int s)
{
    // инициализировать массив значениями true
    for (int i = 0; i < s; i++)
        f[i] = true;
    // избавиться от известных не простых чисел
    f[0] = f[1] = false;
}

void PrimesGenerator::metod(bool* f, int s)
{
    for (int i = 2; i < sqrt(s) + 1; i++)
    {
        if (f[i]) // если i не вычеркнуто, вычеркнуть кратные ему числа
        {
            for (int j = 2 * i; j < s; j += i)
                f[j] = false;  // кратное число не является простым
        }
    }
}

int PrimesGenerator::count(bool* f, int s)
{
    int count = 0;
    for (int i = 0; i < s; i++)
    {
        if (f[i])
            count++; // увеличить счетчик
    }
    return count;
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
    metod(f, s);
    // сколько есть простых чисел?
    std::vector<int> primes(count(f,s));
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
