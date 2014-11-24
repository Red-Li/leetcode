
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
#include <queue>
#endif

class Solution {
    bool symmetricCheck(TreeNode *left, TreeNode *right)
    {
        return (left && right && left->val == right->val)
                || (!left && !right);
   }

        
    bool isSymmetric(TreeNode *left, TreeNode *right)
    {
        if(symmetricCheck(left, right)){
            if(left){
                return isSymmetric(left->left, right->right)
                    && isSymmetric(left->right, right->left);
            }
            else{
                return true;
            }
        }
        else{
            return false;
        }
    }

    bool isSymmetricIter(TreeNode *left, TreeNode *right)
    {
        std::queue<TreeNode*> toCheck;

        toCheck.push(left);
        toCheck.push(right);

        TreeNode *l, *r;
        while(toCheck.size()){
            l = toCheck.front(); toCheck.pop();
            r = toCheck.front(); toCheck.pop();
            
            if(symmetricCheck(l, r)){
                if(l){
                    toCheck.push(l->left); toCheck.push(r->right);
                    toCheck.push(l->right); toCheck.push(r->left);
                }
            }
            else{
                return false;
            }
        }
        
        return true;
    }


public:
    bool isSymmetric(TreeNode *root) {
        if(!root)
            return true;
        else
            return isSymmetricIter(root->left, root->right);
    }

};
