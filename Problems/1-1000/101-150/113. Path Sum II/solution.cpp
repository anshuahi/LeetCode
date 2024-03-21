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
    
    vector<vector<int>> pathSum1(TreeNode* root, int t) {
        if(!root)
            return {};
        if(!root->left && !root->right){
            if(root->val == t)
                return {{t}};
            return {};
        }
        
        vector<vector<int>> l = pathSum1(root->left, t-root->val);
        vector<vector<int>> r = pathSum1(root->right, t-root->val);
        vector<vector<int>> v;
        
        for(auto l1: l){
            l1.push_back(root->val);
            v.push_back(l1);
        }
        
        for(auto l1: r){
            l1.push_back(root->val);
            v.push_back(l1);
        }
        return  v;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        vector<vector<int>> v = pathSum1(root, t);
        for(int i =0; i < v.size(); i++){
            reverse(v[i].begin(), v[i].end());
        }
        
        return v;
    }
};