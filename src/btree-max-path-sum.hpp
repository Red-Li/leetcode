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
    int travalMax(TreeNode *root, int &max)
    {
        if(!root)
            return 0;
        int l = travalMax(root->left, max);
        int r = travalMax(root->right, max);

        int a = std::max(root->val, root->val + std::max(l, r)),
            b = std::max(a, root->val + l + r);
        
        max = std::max(max, std::max(a, b));
        return a;
    }


public:
    int maxPathSum(TreeNode *root) {
        if(!root)
            return 0;
        else{
            int max = INT_MIN;
            travalMax(root, max);
            return max;
        }

    }
};
