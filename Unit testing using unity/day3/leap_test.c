#include "leapyear.h"
#include "unity.h"
#include <stdio.h>
void setUp() {}
void tearDown() {}
void test_leapyear()
{
    TEST_ASSERT_EQUAL(1, isLeapYear(1996));
    TEST_ASSERT_EQUAL(1, isLeapYear(2012));
    TEST_ASSERT_EQUAL(1, isLeapYear(2016));
    TEST_ASSERT_EQUAL(1, isLeapYear(2024));
}
void test_nonleapyear()
{
    TEST_ASSERT_EQUAL(0, isLeapYear(1995));
    TEST_ASSERT_EQUAL(0, isLeapYear(2013));
    TEST_ASSERT_EQUAL(0, isLeapYear(2015));
    TEST_ASSERT_EQUAL(0, isLeapYear(2025));
}
void test_centuries()
{
    TEST_ASSERT_EQUAL(1, isLeapYear(2000));
    TEST_ASSERT_EQUAL(0, isLeapYear(1900));
}
int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_leapyear);
    RUN_TEST(test_nonleapyear);
    RUN_TEST(test_centuries);

    return UNITY_END();
}
