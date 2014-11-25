/**
 * @file contruct-btree-in-post-order-test.cpp
 * @brief 
 * @author Red Li
 * @version 
 * @date 2014-11-25
 */


#include <vector>
#include <gtest/gtest.h>
#include <algorithm>

#include "binary-tree.hpp"

typedef BTreeNodeBase<int> TreeNode;

namespace btree_construct{
#define NAMESPACE
#include "contruct-binary-tree-inorder-postorder.hpp"
}

using namespace btree_construct;
using namespace std;


class BTreeConstructTest : public testing::Test
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


static void traval_tree(TreeNode *node, vector<int> &path, bool in)
{
    if(!node)
        return;

    if(node->left)
        traval_tree(node->left, path, in);

    if(in)
        path.push_back(node->val);

    if(node->right)
        traval_tree(node->right, path, in);

    if(!in)
        path.push_back(node->val);
}


static void checkConstruct(const std::string &ts)
{
    vector<int> inorder, postorder;
    
    std::stringstream is(ts);
    std::stringstream os;
    BTreeBase<int> tree;

    //construct tree from string
    is >> tree;

    //get traval path
    traval_tree(tree.root(), inorder, true);
    traval_tree(tree.root(), postorder, false);

    //construct tree by inorder and postorder path
    Solution sol;
    BTreeBase<int> ctree(
            sol.buildTree(inorder, postorder));

    //convert tree to string
    os << ctree;

    //check result
    std::string ss = os.str();
    EXPECT_EQ(ts, ss);
}



TEST_F(BTreeConstructTest, test)
{
    checkConstruct("");
    checkConstruct("1 0 0");
    checkConstruct("1 2 4 0 0 5 0 0 3 0 6 0 0");

}



