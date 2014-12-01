/**
 * @file reverse-integer-test.cpp
 * @brief 
 * @author Red Li
 * @version 
 * @date 2014-12-01
 */


#include <vector>

#include <gtest/gtest.h>

namespace reverse_integer{
#define NAMESPACE
#include "reverse-integer.hpp"
}


using namespace reverse_integer;

class ReverseIntegerTest : public testing::Test
{
public:
    static void SetUpTestCase()
    {
        
    }
    static void TearDownTestCase()
    {
    }

    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }
};

TEST_F(ReverseIntegerTest, test)
{
    Solution sol;
#if 1
    EXPECT_EQ(sol.reverse(0), 0);
    EXPECT_EQ(sol.reverse(1), 1);
    EXPECT_EQ(sol.reverse(10), 1);
    EXPECT_EQ(sol.reverse(-1), -1);
    EXPECT_EQ(sol.reverse(123), 321);
    EXPECT_EQ(sol.reverse(-123), -321);
#endif
    EXPECT_EQ(sol.reverse(2147483647), 0);
	EXPECT_EQ(sol.reverse(2147483641), 1463847412);
	EXPECT_EQ(sol.reverse(-2147483648), 0);
	EXPECT_EQ(sol.reverse(-2147483641), -1463847412);
}
