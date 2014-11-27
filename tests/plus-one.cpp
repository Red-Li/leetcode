/**
 * @file plus-one.cpp
 * @brief 
 * @author Red Li
 * @version 
 * @date 2014-11-26
 */


#include <vector>

#include <gtest/gtest.h>

namespace plus_one{
#define NAMESPACE
#include "plus-one.hpp"
}


using namespace plus_one;

class PlusOneTest : public testing::Test
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

TEST_F(PlusOneTest, test)
{
    std::vector<int> d0, d1, d2;
    std::vector<int> r0, r1, r2;
    
    d1.push_back(9);
    d2.push_back(9);
    d2.push_back(9);

    Solution sol;

    r0 = sol.plusOne(d0);
    r1 = sol.plusOne(d1);
    r2 = sol.plusOne(d2);
    

}
