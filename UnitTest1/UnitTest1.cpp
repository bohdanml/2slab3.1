#include "pch.h"
#include "CppUnitTest.h"
#include"..//2slab3.1/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestConstructor)
		{
			Pair p(19, 20);
			Assert::AreEqual(19, p.getFirst());
			Assert::AreEqual(20, p.getSecond());
		}
	};
}
