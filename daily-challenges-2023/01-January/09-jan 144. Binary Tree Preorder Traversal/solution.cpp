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

    // void

    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        vector<int> l = preorderTraversal(root->left);
        vector<int> r = preorderTraversal(root->right);
        l.insert(l.begin(), root->val);
        for(auto x: r){
            l.push_back(x);
        }
        
        return l;
    }
};