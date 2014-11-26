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
    void inorder(std::vector<int> &res, TreeNode *root)
    {
        if(root->left)
            inorder(res, root->left);
        res.push_back(root->val);
        if(root->right)
            inorder(res, root->right);
    }

public:
    vector<int> inorderTraversal(TreeNode *root) {
        std::vector<int> res;
        
        if(root)
            inorder(res, root);

        return std::move(res);
    }
};
