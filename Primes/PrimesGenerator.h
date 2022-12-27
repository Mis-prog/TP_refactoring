#pragma once
/*
* ���� ����� ���������� ������� ����� �� ���������� �������������
* ���������. ������������ �������� "������ ����������".
* �������� �������� �����. ��� ������ ����� �����, ������������ � 2.
* ��������� �� ���� ��� �����, ������� 2. ������ ��������� �������������
* ����� � ��������� ��� ������� ��� �����. ��������� �� ��� ���, ����
* �� ������ �� �����, ����������� ���������� ������ ������������� ��������.
* 
* @author Robert C.Martin (Java version)
*/

#include <cmath>
#include <vector>

class PrimesGenerator
{
private:
	static void set(bool* f, int s);
	static void metod(bool* f, int s);
  // @param maxValue - ������ ���������
public:
  static std::vector<int> generatePrimes(int maxValue);
};

