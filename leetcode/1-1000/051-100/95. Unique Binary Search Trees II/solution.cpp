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
#define pb push_back

class Solution {
public:
    vector<TreeNode*> makeTree(int n, int s, int e){
        if(n <= 0){
            return {NULL};
        }
        if(n == 1){
            return {new TreeNode(s)};
        }
        vector<TreeNode*> v, l, r;
        TreeNode* u;

        for(int i= s; i <= e; i++){
            // u = new TreeNode(i);
            l = makeTree(i-s, s, i-1);
            r = makeTree(e-i, i+1, e);
            for(auto x: l){
                for(auto y: r){
                    u = new TreeNode(i, x, y);
                    v.pb(u);
                }
            }
        }

        return v;
    }


    vector<TreeNode*> generateTrees(int n) {
        return makeTree(n, 1, n);
    }
};