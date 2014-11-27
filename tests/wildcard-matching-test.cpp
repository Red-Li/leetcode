/**
 * @file wildcard-matching-test.cpp
 * @brief 
 * @author Red Li
 * @version 
 * @date 2014-11-27
 */


#include <gtest/gtest.h>

#include <vector>
using namespace std;
namespace wildcard_matching{
#define NAMESPACE
#include "wildcard-matching.hpp"
}


using namespace wildcard_matching;

class WildcardMatchingTest : public testing::Test
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


TEST_F(WildcardMatchingTest, test)
{
    Solution sol;   
    
    EXPECT_TRUE(sol.isMatch("", ""));
    EXPECT_TRUE(sol.isMatch("", "*"));
    EXPECT_FALSE(sol.isMatch("", "?"));
    //EXPECT_TRUE(sol.isMatch("ccaa", "*a*"));
    //EXPECT_TRUE(sol.isMatch("ccaa", "c*?*"));
    //EXPECT_TRUE(sol.isMatch("ccaa", "?*a*"));
    //EXPECT_TRUE(sol.isMatch("ccaa", "?*****a*"));

}
