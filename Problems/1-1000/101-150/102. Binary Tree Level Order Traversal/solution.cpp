/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root == NULL)
            return v;
        queue<TreeNode*> q, q2;
        
        q.push(root);
        
        while(!q.empty()){
            vector<int> x;
            while(!q.empty()) {
                TreeNode* f = q.front(); q.pop();
                x.push_back(f->val);
                if(f->left)
                    q2.push(f->left);
                if(f->right)
                    q2.push(f->right);
            }
            v.push_back(x);
            q = q2;
            while(!q2.empty()){
                q2.pop();
            }
        }
        
        return v;
    }
};