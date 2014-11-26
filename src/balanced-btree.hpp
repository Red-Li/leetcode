/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int height(TreeNode *root)
    {
        if(!root)
            return 0;

        int lh = height(root->left),
            rh = height(root->right);
        
        if(lh < 0 || rh < 0 || abs(lh - rh) > 1)
            return -1;
        else
            return (lh > rh ? lh : rh) + 1;
    }

public:
    bool isBalanced(TreeNode *root) {
        return height(root) >= 0;
    }
};
