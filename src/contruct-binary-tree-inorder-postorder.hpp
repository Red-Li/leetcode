/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#ifndef NAMESPACE
#include <vector>
#include <algorithm>
#endif

using namespace std;

class Solution {
    typedef vector<int>::iterator iterator;

    TreeNode *buildTree(iterator inBegin, iterator inEnd,
                        iterator postBegin, iterator postEnd)
    {
        if(inBegin == inEnd)
            return 0;
        
        iterator rootIt = find(inBegin, inEnd, *(postEnd - 1));
        //assert(rootIt != inEnd)
        
        TreeNode *root = new TreeNode(*rootIt);
        root->left = buildTree(inBegin, rootIt, 
                                 postBegin, postBegin + (rootIt - inBegin));
        root->right = buildTree(rootIt + 1, inEnd,
                                  postBegin + (rootIt - inBegin), postEnd - 1);

        return root;
    }


public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
#if 0
        if(!inorder.size())
            return 0;

        vector<int>::iterator rootIt = 
            std::find(inorder.begin(), inorder.end(), postorder.back());
        //assert(rootIt != inorder.end())
        
        std::vector<int> lin(inorder.begin(), rootIt),
                         lpost(postorder.begin(), postorder.begin() + lin.size());
        std::vector<int> rin(rootIt + 1, inorder.end()),
                         rpost(postorder.begin() + lin.size(), postorder.end() - 1);
        
        TreeNode *root = new TreeNode(*rootIt);
        root->left = buildTree(lin, lpost);
        root->right = buildTree(rin, rpost);

        return root;
#else
        return buildTree(inorder.begin(), inorder.end(),
                         postorder.begin(), postorder.end());
#endif
    }
};
