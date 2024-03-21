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
    
    bool isValid(TreeNode* root, long l, long r){
        if(root == NULL){
            return true;
        }
        long p = root->val;        
        
        if(root->val >= l && root->val <= r){
            return isValid(root->left, l, p-1) && isValid(root->right, p+1, r);
        }
        
        return false;
    }
    
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return true;
        
        return isValid(root, INT_MIN, INT_MAX);
        
    }
};