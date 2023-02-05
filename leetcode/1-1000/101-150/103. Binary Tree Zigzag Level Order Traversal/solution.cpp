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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<vector<int>> v;
        
        queue<TreeNode*> q1, q2;
        q1.push(root);
        
        while(!q1.empty()){
            vector<int> v1;
            while(!q1.empty()){
                TreeNode* t = q1.front();
                q1.pop();
                if(!t)
                    continue;
                v1.push_back(t->val);
                q2.push(t->left);
                q2.push(t->right);
            }
            if(v1.size())
                v.push_back(v1);
            q1 = q2;
            while(!q2.empty()){
                q2.pop();
            }
        }
        
        for(int i = 1; i < v.size(); i+=2){
            reverse(v[i].begin(), v[i].end());
        }
        
        
        return v;
    }
};