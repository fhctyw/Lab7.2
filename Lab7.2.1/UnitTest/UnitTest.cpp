#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab7.2.1\Main.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int** arr = new int* [3];
			arr[0] = new int[2]{ 0, 2 };
			arr[1] = new int[2]{ 1, 1 };
			arr[2] = new int[2]{ -1, 0 };

			int maxElem;
			SearchMaxElem(arr, 3, 2, maxElem);
			Assert::AreEqual(0, maxElem);
		}
	};
}
