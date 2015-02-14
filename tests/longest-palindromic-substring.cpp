

#include <sstream>

#include <gtest/gtest.h>

#include <unordered_set>
using namespace std;

namespace longest_palindromic_substring{
#define NAMESPACE
#include "longest-palindromic-substring.hpp"
}

using namespace longest_palindromic_substring;

class LongestPalindromicSubstringTest : public testing::Test
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

TEST_F(LongestPalindromicSubstringTest, test)
{
    Solution sol;

    EXPECT_EQ(sol.longestPalindrome("abcba"), "abcba");
    EXPECT_EQ(sol.longestPalindrome("abcbd"), "bcb");
    EXPECT_EQ(sol.longestPalindrome("abcbdb"), "bcb");
    EXPECT_EQ(sol.longestPalindrome("bb"), "bb");
    EXPECT_EQ(sol.longestPalindrome("acbbba"), "bbb");
    EXPECT_EQ(sol.longestPalindrome("acbbbba"), "bbbb");
}
