#include "pch.h"
#include "CppUnitTest.h"
#include "../AP12.2rek/AP12.2rek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest122rek
{
	TEST_CLASS(UnitTest122rek)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* first = NULL, * last = NULL;
			Input(first, last, 1);
			Assert::IsNotNull(first);
			Assert::IsNotNull(last);
			Assert::AreEqual(first->info, 1);
			Assert::AreEqual(last->info, 1);

			DeleteAfter(first, 1);
			
			
		}
	};
}
