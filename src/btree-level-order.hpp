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
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > res;

        if(root){
            std::queue<TreeNode*> q;
            q.push(root);
            int lsize = 1;
            
            while(!q.empty()){
                res.push_back(vector<int>());
                vector<int> &back = res.back();

                int c = 0;
                for(int i = 0; i < lsize; ++i){
                    back.push_back(q.front()->val);
                    if(q.front()->left){
                        ++c;
                        q.push(q.front()->left);
                    }
                    if(q.front()->right){
                        ++c;
                        q.push(q.front()->right);
                    }
                    q.pop();
                }

                lsize = c;
            }
        }

        return std::move(res);
    }
};
