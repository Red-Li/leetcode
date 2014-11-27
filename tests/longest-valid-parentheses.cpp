/**
 * @file longest-valid-parentheses.hpp
 * @brief 
 * @author Red Li
 * @version 
 * @date 2014-11-26
 */

#include <sstream>

#include <gtest/gtest.h>

#include <stack>
namespace longest_parentheses{
#include "longest-valid-parentheses.hpp"
}

using namespace longest_parentheses;

class LongestValidParentheses: public testing::Test
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


TEST_F(LongestValidParentheses, test)
{
    Solution sol;

    EXPECT_EQ(sol.longestValidParentheses(")"), 0);
    EXPECT_EQ(sol.longestValidParentheses("("), 0);
    EXPECT_EQ(sol.longestValidParentheses("()"), 2);
    EXPECT_EQ(sol.longestValidParentheses("()(()"), 2);
    EXPECT_EQ(sol.longestValidParentheses("()(()()"), 4);
    EXPECT_EQ(sol.longestValidParentheses("()((()())"), 6);
    EXPECT_EQ(sol.longestValidParentheses("()()(()"), 4);
    EXPECT_EQ(sol.longestValidParentheses("(()(((()"), 2);

}


