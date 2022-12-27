#include "pch.h"
#include "CppUnitTest.h"
#include "../Primes/PrimesGenerator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testrefactoring
{
	TEST_CLASS(Testrefactoring)
	{
	public:
		
        TEST_METHOD(Test1)
        {
            std::vector<int> result = { 2,3,5,7 };
            std::vector<int> arr = PrimesGenerator::generatePrimes(10);
            Assert::IsTrue(result == arr);
        }
        TEST_METHOD(Test2)
        {
            std::vector<int> result = {};
            std::vector<int> arr = PrimesGenerator::generatePrimes(1);
            Assert::IsTrue(result == arr);
        }
        TEST_METHOD(Test3)
        {
            std::vector<int> result = { 2 };
            std::vector<int> arr = PrimesGenerator::generatePrimes(2);
            Assert::IsTrue(result == arr);
        }
	};
}
