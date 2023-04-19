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
#define ppii pair<int, pii>
class Solution {
public:
    int ans;
    ppii findBST(TreeNode* root){
        if(!root){
            return {0, {INT_MIN, INT_MIN}};
        }
        int x = root->val;
        if(!root->left && !root->right){
            ans = max(ans, x);
            return {x,{x, x}};
        }
        ppii l = findBST(root->left);
        ppii r = findBST(root->right);
        if(l.second.first == INT_MAX || r.second.first == INT_MAX){
            return {INT_MAX, {INT_MAX, INT_MAX}};
        }
        if(root->left && root->right){
            if(l.second.second < x && x < r.second.first){
                ans = max(ans, x+l.first+r.first);
                return {x+l.first+r.first, {l.second.first, r.second.second}};
            }
            return {INT_MAX, {INT_MAX, INT_MAX}};
        }
        if(root->left){
            if(l.second.second < x){
                ans = max(ans, x+l.first);
                return {x+l.first, {l.second.first, x}};
            }
            return {INT_MAX, {INT_MAX, INT_MAX}};
        }
        if(root->right){
            if(x < r.second.first){
                ans = max(ans, x+r.first);
                return {x+r.first, {x, r.second.second}};
            }
            return {INT_MAX, {INT_MAX, INT_MAX}};
        }
        return {INT_MAX, {INT_MAX, INT_MAX}};

    }

    int maxSumBST(TreeNode* root) {
        ans = 0;
        findBST(root);
        return ans;
    }
};