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
    
    bool sym(TreeNode* a, TreeNode* b) {
        if(a == NULL && b == NULL)
            return true;
        if(a == NULL && b){
            return false;
        }
        if(b == NULL && a != NULL)
            return false;
        if(a->val != b->val)
            return false;
        return sym(a->left, b->right) && sym(a->right, b->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return sym(root->left, root->right);
    }
};