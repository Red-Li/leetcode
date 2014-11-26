/**
 * @file permutation-seq-test.cpp
 * @brief 
 * @author Red Li
 * @version 
 * @date 2014-11-26
 */

#include <algorithm>
#include <string>
#include <gtest/gtest.h>

namespace permutation_seq{
#define NAMESPACE
#include "permutation-seq.hpp"
}

using namespace permutation_seq;


class PermutationSeqTest : public testing::Test
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


TEST_F(PermutationSeqTest, test)
{
    Solution sol;

    EXPECT_EQ(sol.getPermutation(1, 1), "1");

    EXPECT_EQ(sol.getPermutation(3, 1), "123");
    EXPECT_EQ(sol.getPermutation(3, 2), "132");
    EXPECT_EQ(sol.getPermutation(3, 3), "213");
    EXPECT_EQ(sol.getPermutation(3, 4), "231");
    EXPECT_EQ(sol.getPermutation(3, 5), "312");
    EXPECT_EQ(sol.getPermutation(3, 6), "321");


}
