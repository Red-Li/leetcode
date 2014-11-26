/**
 * @file permutations-test.cpp
 * @brief 
 * @author Red Li
 * @version 
 * @date 2014-11-26
 */


#include <vector>
#include <gtest/gtest.h>

namespace permutations{
#define NAMESPACE
#include "permutations.hpp"
}

using namespace permutations;

class PermutationsTest : public testing::Test
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


TEST_F(PermutationsTest, test)
{
    std::vector<int> num0, num1, num2;
    std::vector<std::vector<int> > r0, r1, r2;
    
    Solution sol;

    num1.push_back(1);
    num2.push_back(1);
    num2.push_back(2);
    num2.push_back(3);

    r0 = sol.permute(num0);
    r1 = sol.permute(num1);
    r2 = sol.permute(num2);
}
