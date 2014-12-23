/**
 * @file find-min-in-rotated-sorted-array.cpp
 * @brief 
 * @author Red Li
 * @version 
 * @date 2014-12-22
 */


#include <vector>
#include <gtest/gtest.h>
#include <algorithm>

using namespace std;

namespace find_min_in_rotated_sorted_array{
#include "find-min-in-rotated-sorted-array.hpp"
}

using namespace find_min_in_rotated_sorted_array;


class FindMinInRoratedSortedArray: public testing::Test
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

TEST_F(FindMinInRoratedSortedArray, test)
{
    Solution sol;
    int t0[] = {0},
        t1[] = {0, 1, 2, 3},
        t2[] = {0, 1, 2, 3, 4},
        t3[] = {1, 2, 3, 4, 0},
        t4[] = {2, 3, 4, 0, 1};

#define APPLY_TEST(t, ret) do{\
	vector<int> v_t(t, t + sizeof(t) / 4);\
    EXPECT_EQ(sol.findMin(v_t), ret);\
}while(0)


    APPLY_TEST(t0, 0);
    APPLY_TEST(t1, 0);
    APPLY_TEST(t2, 0);
    APPLY_TEST(t3, 0);
    APPLY_TEST(t4, 0);


#undef APPLY_TEST


}
