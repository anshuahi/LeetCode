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
#define pii pair<TreeNode*, int>
#define pb push_back

class Solution {
public:
    
    int height(TreeNode* root){
        if(!root)
            return 0;
        return 1+ max(height(root->left), height(root->right));
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root){
            return {};
        }
        int h = height(root);
        vector<vector<int>> v(h);
        // int i = 0;
        queue<pii> q;
        q.push({root, 0});
        
        while(!q.empty()){
            pii p = q.front();
            q.pop();
            if(!p.first)
                continue;
            int ind = p.second;
            v[ind].pb(p.first->val);
            q.push({p.first->left, ind+1});
            q.push({p.first->right, ind+1});
        }
        
        reverse(v.begin(), v.end());
        return v;
    }
};