/*
LeetCode-POTD: 2331. Evaluate Boolean Binary Tree

POTD Link - https://leetcode.com/problems/evaluate-boolean-binary-tree/description/

Approach
    1. try recursively evaluate the answer for each node

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
    bool evaluateTree(TreeNode *root)
    {
        if (!root->left && !root->right)
        {
            return root->val == 1;
        }

        bool l = evaluateTree(root->left);
        bool r = evaluateTree(root->right);

        if (root->val == 2)
        {
            return l || r;
        }
        return l && r;
    }
};
