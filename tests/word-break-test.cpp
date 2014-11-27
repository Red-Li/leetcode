/**
 * @file word-break-test.cpp
 * @brief 
 * @author Red Li
 * @version 
 * @date 2014-11-27
 */


#include <sstream>

#include <gtest/gtest.h>

#include <unordered_set>
using namespace std;

namespace word_break{
#define NAMESPACE
#include "word-break.hpp"
}

using namespace word_break;

class WordBreakTest : public testing::Test
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

TEST_F(WordBreakTest, test)
{
    unordered_set<string> dict;

    dict.insert("a");
    dict.insert("aa");
    dict.insert("aaa");
    dict.insert("aaaa");
    dict.insert("aaaaa");

    Solution sol;
    EXPECT_TRUE(sol.wordBreak("", dict));
    EXPECT_TRUE(sol.wordBreak("aaaaaaaaaaaaaaaa", dict));

}
