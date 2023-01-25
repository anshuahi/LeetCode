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
    
    TreeNode* flat(TreeNode* root){
        if(root == NULL){
            return NULL;
        }
        
        TreeNode* l = flat(root->left);
        TreeNode* r = flat(root->right);
        
        root->left = NULL;
        
        if(l == NULL){
            root->right = r;
        }
        else {
            root->right = l;
            TreeNode* t = l;
            while(t->right){
                t = t->right;
            }
            t->right = r;
        }
        
        return root;
    }
    
    void flatten(TreeNode* root) {
        root = flat(root);
        
    }
};