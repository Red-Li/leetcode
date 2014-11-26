/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <algorithm>

class Solution {
    void minDepth(TreeNode *root, int &depth, int &min)
    {
        ++depth;

        if(!root->left && !root->right){
            min = std::min(min, depth);   
        }
        else{
            if(root->left)
                minDepth(root->left, depth, min);
            if(root->right)
                minDepth(root->right, depth, min);
        }
        --depth;
    }


public:
    int minDepth(TreeNode *root) {
        if(!root)
            return 0;

        int depth, min = INT_MAX;
        minDepth(root, depth, min);

        return min;
    }
};
