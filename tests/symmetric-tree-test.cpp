/**
 * @file symmetric-tree-test.cpp
 * @brief 
 * @author Red Li
 * @version 
 * @date 2014-11-24
 */

#include <sstream>

#include <gtest/gtest.h>

#include "binary-tree.hpp"

class symmetric_tree_test : public testing::Test
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


void btreeCheck(const std::string &s)
{
    std::stringstream is(s);
    std::stringstream os;
    BTreeBase<int> tree;

    is >> tree;
    os << tree;

    std::string ss = os.str();
    EXPECT_EQ(s, ss);
}



TEST_F(symmetric_tree_test, binary_tree_read_write)
{
	btreeCheck("");
    btreeCheck("1 2 4 0 0 5 0 0 3 0 6 0 0");

}

