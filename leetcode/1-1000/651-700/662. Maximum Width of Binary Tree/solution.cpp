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

#define ll long long 
#define pii pair<int, int>
class Solution {
public:
    ll ans;
    vector<ll> left, right;
    int height(TreeNode* root){
        if(!root)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    void dfs1(TreeNode* root, int level, ll l){
        if(!root){
            return ;
        }
        left[level] = min(left[level], l);
        right[level] = max(right[level], l);

        dfs1(root->left, level+1, l*2);
        dfs1(root->right, level+1, l*2+1);
    }
    void dfs2(TreeNode* root, int level, ll r){
        if(!root){
            return ;
        }
        right[level] = max(right[level], r);
        left[level] = min(left[level], r);

        dfs2(root->left, level+1, r*2-1);
        dfs2(root->right, level+1, 2*r);
    }

    int widthOfBinaryTree(TreeNode* root) {
        // vector<ll> 
        ans = 1;
        while(true){
            if(!root){
                break;
            }
            if(root->left == NULL){
                root = root->right;
            }
            if(!root){
                break;
            }
            if(root->right == NULL){
                root = root->left;
            }
            
            if(!root){
                break;
            }
            if(root->left && root->right){
                break;
            }
        }
        int h = height(root);
        left.resize(h, INT_MAX), right.resize(h, INT_MIN);
        if(!root)
            return ans;

        dfs1(root->left, 1, -1);
        dfs2(root->right, 1, 1);

        for(int i = 0; i < h; i++){
            // cout << i << " ->\t " << left[i] << " " << right[i] << endl;
            if(right[i] != INT_MIN && left[i] != INT_MAX){
                if(right[i] > 0 && left[i] < 0){
                    ans = max(ans, right[i] - left[i]);
                }
                else {
                    ans = max(ans, abs(right[i] - left[i])+1);
                }
            }
        }

        return ans;
    }
};