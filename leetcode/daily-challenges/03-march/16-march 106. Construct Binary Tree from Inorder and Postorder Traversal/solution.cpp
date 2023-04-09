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
    int pInd;
    
    int find(vector<int> &v, int t){
        for(int i = 0; i < v.size(); i++){
            if(v[i] == t)
                return i;
        }
        
        return -1;
    }
    
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int s, int e){
        if(s > e)
            return NULL;
        
        int val = postorder[pInd--];
        cout << val << " ";
        TreeNode* x = new TreeNode(val);
        
        if(s == e)
            return x;
        
        int ind = find(inorder, val);
        
        x->right = helper(inorder, postorder, ind+1, e);
        x->left = helper(inorder, postorder, s, ind-1);
        
        return x;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if(n == 0)
            return NULL;
        if(n == 1)
            return new TreeNode(inorder[0]);
        pInd = n-1;
        
        return helper(inorder, postorder, 0, n-1);
    }
};