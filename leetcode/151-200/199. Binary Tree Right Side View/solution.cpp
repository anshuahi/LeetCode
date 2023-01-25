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
    
    int height(TreeNode* root){
        if(!root){
            return 0;
        }
        
        return 1 + max(height(root->left), height(root->right));
    }
    
    void traverse(TreeNode* root, vector<int> &v, int i){
        if(!root)
            return;
        if(v[i] == -111){
            v[i] = root->val;
        }
        traverse(root->right, v, i+1);
        traverse(root->left, v, i+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        int h = height(root);
        // cout << h << endl;
        vector<int> v(h, -111);
        traverse(root, v, 0);
        return v;
    }
};