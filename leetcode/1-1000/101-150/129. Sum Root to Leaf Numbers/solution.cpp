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
    int ans = 0;
    void find(TreeNode* root, int x){
        if(!root){
            return;
        }
        
        if(!root->left && !root->right){
            // cout << x << " ";
            ans += (x*10 + root->val);
            return;
        }
        
        find(root->left, x*10+root->val);
        find(root->right, x*10+root->val);
        
    }
    
    int sumNumbers(TreeNode* root) {
        ans = 0;
        find(root,0);
        return ans;
    }
};