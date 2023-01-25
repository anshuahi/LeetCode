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
    
    TreeNode* sort(vector<int> &v, int s, int e){
        if(s > e){
            return NULL;
        }
        if(s == e){
            return new TreeNode(v[s], NULL, NULL);
        }
        int mid = (s+e)/2;
        TreeNode* l = sort(v, s, mid-1);
        TreeNode* r = sort(v, mid+1, e);
        
        TreeNode* root = new TreeNode(v[mid], l, r);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sort(nums, 0, nums.size()-1);
    }
};