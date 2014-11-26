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

typedef BTreeNodeBase<int> TreeNode;

#include <queue>
namespace sym_tree{
#define NAMESPACE
#include "symmetric-tree.hpp"
}


using namespace sym_tree;

class SymmetricTreeTest : public testing::Test
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



TEST_F(SymmetricTreeTest, BTreeSerilization)
{
	btreeCheck("");
    btreeCheck("1 2 4 0 0 5 0 0 3 0 6 0 0");
}


void symmetricCheck(const std::string &s, bool expect)
{
    std::stringstream is(s);
    BTreeBase<int> tree;
    Solution sol;

    is >> tree;

    EXPECT_EQ(sol.isSymmetric(tree.root()), expect);
}

TEST_F(SymmetricTreeTest, isSymmetric)
{
    //
    symmetricCheck("", true);
    symmetricCheck("1 0 0", true);
    symmetricCheck("1 2 0 0 2 0 0", true);
    symmetricCheck("1 2 3 0 0 0 2 0 3 0 0", true);
    symmetricCheck("1 2 3 0 0 4 0 0 2 4 0 0 3 0 0", true);

    //
    symmetricCheck("1 2 0 0 0", false);
    symmetricCheck("1 0 2 0 0", false);
    symmetricCheck("1 2 3 0 0 0 2 3 0 0 0", false);

}

