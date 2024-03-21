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
    unordered_map<int, TreeNode*> mp;
        vector<int> v,u;

    void inOrder(TreeNode* root) {
        if(root == NULL)
            return;
        inOrder(root->left);
        v.push_back(root->val);
        u.push_back(root->val);
        mp[root->val] = root;
        inOrder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inOrder(root);
        vector<TreeNode*> vt;
        sort(u.begin(), u.end());
        for(int i = 0; i < v.size(); i++){
            if(v[i] != u[i]){
                vt.push_back(mp[v[i]]);
            }
        }
        swap(vt[0]->val, vt[1]->val);
    }
};