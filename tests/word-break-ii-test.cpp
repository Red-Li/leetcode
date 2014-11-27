/**
 * @file word-break-ii-test.cpp
 * @brief 
 * @author Red Li
 * @version 
 * @date 2014-11-27
 */


#include <sstream>

#include <gtest/gtest.h>

#include <unordered_set>
using namespace std;

namespace word_break_ii{
#define NAMESPACE
#include "word-break-ii.hpp"
}

using namespace word_break_ii;

class WordBreakIITest : public testing::Test
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

TEST_F(WordBreakIITest, test)
{
    unordered_set<string> dict;

    dict.insert("cat");
    dict.insert("cats");
    dict.insert("and");
    dict.insert("sand");
    dict.insert("dog");

    Solution sol;
    vector<string> res = sol.wordBreak("catsanddog", dict);
}
