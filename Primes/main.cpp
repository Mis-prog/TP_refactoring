#include <iostream>
#include "PrimesGenerator.h"

using namespace std;

int main()
{
  vector<int> arr = PrimesGenerator::generatePrimes(10);
  for (auto number : arr)
    cout << number << " ";

  return 0;
}