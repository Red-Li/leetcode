/**
 * @file contruct-btree-in-post-order-test.cpp
 * @brief 
 * @author Red Li
 * @version 
 * @date 2014-11-25
 */

#include <string>
#include <gtest/gtest.h>
#include <algorithm>

using namespace std;
namespace reverse_words{
#include "reverse-words-in-a-string.hpp"
}

using namespace reverse_words;

class ReverseWordsTest : public testing::Test
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



TEST_F(ReverseWordsTest, test)
{
    Solution sol;
    
    std::string s0("the sky is blue");
    std::string s1("  the sky is   blue   ");

    sol.reverseWords(s0);
    sol.reverseWords(s1);

}


