#include "unity.h"
#include <stdio.h>
#include "demo.h"
void setUp() {}
void tearDown() {}
void test_sum()
{
    TEST_ASSERT_EQUAL(3, sum(1, 2));
    TEST_ASSERT_EQUAL(9, sum(6, 4));
}
int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_sum);
    return UNITY_END();
}