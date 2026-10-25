#include "pch.h"
#include "CppUnitTest.h"
#include "../lab064rec/lab064rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64Rec
{
    TEST_CLASS(UnitTest64Rec)
    {
    public:

        TEST_METHOD(TestMaxIndex)
        {
            int a[7] = { 3, 0, 2, -1, 4, 0, 5 };
            Assert::AreEqual(6, MaxIndex(a, 7, 0, 0));
        }

        TEST_METHOD(TestFindZero)
        {
            int a[7] = { 3, 0, 2, -1, 4, 0, 5 };
            Assert::AreEqual(1, FindZero(a, 7, 0));
            Assert::AreEqual(5, FindZero(a, 7, 2));
        }

        TEST_METHOD(TestProduct)
        {
            int a[7] = { 3, 0, 2, -1, 4, 0, 5 };
            Assert::AreEqual(-8, Product(a, 5, 2));
        }

        TEST_METHOD(TestRearrange)
        {
            int a[7] = { 1, 2, 3, 4, 5, 6, 7 };
            Rearrange(a, 7);
            int expected[7] = { 1, 3, 5, 7, 2, 4, 6 };
            for (int i = 0; i < 7; i++)
                Assert::AreEqual(expected[i], a[i]);
        }
    };
}
