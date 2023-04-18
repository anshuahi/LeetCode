// Genius Solution
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
#define pii pair<int, int>
#define pb push_back

class Solution {
public:

    vector<int> sum;
    int height(TreeNode* root){
        if(!root)
            return 0;
        return 1 + max(height(root->right), height(root->left));
    }
    
    void dfs(TreeNode* root, int parent, int level){
        if(!root)
            return;
        sum[level] += root->val;
        dfs(root->left, root->val, level+1);
        dfs(root->right, root->val, level+1);
    }
    
    TreeNode* makeCousinTree(TreeNode* root, TreeNode* parent, int level, int ans){
        if(!root || !parent)
            return NULL;

        root->val = sum[level] - ans;
        ans = 0;
        if(root->left){
            ans += root->left->val;
        }
        if(root->right){
            ans += root->right->val;
        }
        
        root->left = makeCousinTree(root->left, root, level+1, ans);
        root->right = makeCousinTree(root->right, root, level+1, ans);
        
        return root;
    }
    
    TreeNode* replaceValueInTree(TreeNode* root) {
        int h = height(root);
        sum.clear();
        sum.resize(h);
        dfs(root, -1, 0);
        
        int ans = 0;
        if(root->left){
            ans += root->left->val;
        }
        if(root->right){
            ans += root->right->val;
        }
        
        return new TreeNode(0, makeCousinTree(root->left, root, 1, ans), makeCousinTree(root->right, root, 1, ans));
    }
};
