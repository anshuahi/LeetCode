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
#define pii pair<int, char>
class Solution {
public:
    int ans;

    pii findLongest(TreeNode* root, char order){
        if(!root){
            return {0, order};
        }
        if(!root->left && !root->right){
            return {1, order};
        }
        pii l = findLongest(root->left, 'l');
        pii r = findLongest(root->right, 'r');

        if(order == 'l'){
            ans = max(ans, r.first+1);
            return {r.first+1, 'l'};
        }
        ans = max(ans, l.first+1);
        return {l.first+1, 'r'};
    }

    int longestZigZag(TreeNode* root) {
        ans = 0; 
        findLongest(root->left, 'l');   
        findLongest(root->right, 'r');
        return ans;
    }
};