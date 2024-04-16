/*
LeetCode-POTD: 623. Add One Row to Tree

POTD Link - https://leetcode.com/problems/add-one-row-to-tree/description

GitHub Solution Link- https://github.com/anshuahi/LeetCode/blob/main/daily-challenges-2024/16_04_2024.cpp

Approach :
    1. go to depth=2, and insert the new node in the next level
    2. insert the new node recursively at all place(@depth)

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
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            return new TreeNode(val, root, NULL);
        }
        if (!root)
        {
            return root;
        }
        if (depth == 2)
        {
            root->left = new TreeNode(val, root->left, NULL);
            root->right = new TreeNode(val, NULL, root->right);
            return root;
        }
        root->left = addOneRow(root->left, val, depth - 1);
        root->right = addOneRow(root->right, val, depth - 1);
        return root;
    }
};