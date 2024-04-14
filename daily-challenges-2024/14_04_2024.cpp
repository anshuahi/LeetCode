/*
LeetCode-POTD: 404. Sum of Left Leaves

POTD Link - https://leetcode.com/problems/sum-of-left-leaves/description/

Approach :
1. check if root->left is a leaf node, and add its value to ans
2. repeat it recursively

*/
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
class Solution
{
public:
    bool isLeaf(TreeNode *root)
    {
        return root && !root->left && !root->right;
    }

    int sumOfLeftLeaves(TreeNode *root)
    {
        if (!root)
            return 0;
        int ans = 0;
        if (isLeaf(root->left))
            ans += root->left->val;
        ans += sumOfLeftLeaves(root->left);
        ans += sumOfLeftLeaves(root->right);

        return ans;
    }
};
