/**
 * @file multiple-strings-test.cpp
 * @brief 
 * @author Red Li
 * @version 
 * @date 2014-12-02
 */


#include <string>
#include <gtest/gtest.h>

namespace multiple_string{
#define NAMESPACE
using namespace std;
#include "multiple-strings.hpp"
}
using namespace multiple_string;


class MultipleStringTest : public testing::Test
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


TEST_F(MultipleStringTest, test)
{
    Solution sol;
    EXPECT_EQ(sol.multiply("", ""), string("0"));
    EXPECT_EQ(sol.multiply("123", "0"), string("0"));
    EXPECT_EQ(sol.multiply("123", "2"), string("246"));
    EXPECT_EQ(sol.multiply("123", "22"), string("2706"));
}
