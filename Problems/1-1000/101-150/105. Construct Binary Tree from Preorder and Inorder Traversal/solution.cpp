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
    
    int find(vector<int> &v, int x) {
        for(int i = 0; i < v.size(); i++) {
            if(v[i] == x)
                return i;
        }
        
        return -1;
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int sp, int ep, int &in){
        // cout << sp << " " << ep << "\n ";// << si << " " << ei << endl;
        
        if(sp > ep){
            return NULL;
        }

        int x = preorder[in++];
        if(sp == ep){
            return new TreeNode(x);
        }
        
        int ind = find(inorder, x);
        
        TreeNode* l = build(preorder, inorder, sp, ind-1, in);
        TreeNode* r = build(preorder, inorder, ind+1, ep, in);
        return new TreeNode(x, l, r);
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0){
            return NULL;
        }
        int ind = 0;
        return build(preorder, inorder, 0, preorder.size()-1, ind);
    }
};