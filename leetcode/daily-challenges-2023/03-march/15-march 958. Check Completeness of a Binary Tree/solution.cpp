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
        if(!root)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    void dfs(TreeNode* root, vector<int> &v, int level, vector<int> &last){
        if(!root)
            return;
        v[level]++;
        if(level == v.size()-2){
            last.push_back(root->left? root->left->val: -1);
            last.push_back(root->right? root->right->val: -1);
        }
        dfs(root->left, v, level+1, last);
        dfs(root->right, v, level+1, last);
    }

    bool isCompleteTree(TreeNode* root) {
        if(!root){
            return true;
        }
        if(!root->right && !root->left){
            return true;
        }
        int h = height(root);

        vector<int> v(h);
        vector<int> last;
        dfs(root, v, 0, last);
        // for(auto x: last){
        //     cout << x<< " ";
        // }

        for(int i = 1; i < h-1; i++){
            if(v[i] != 2*v[i-1]){
                return false;
            }
        }

        for(int i = 1; i < last.size(); i++){
            if(last[i] != -1 && last[i-1] == -1){
                return false;
            }
        }

        return true;
    }
};