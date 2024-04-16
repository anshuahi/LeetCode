/*
LeetCode-POTD: 129. Sum Root to Leaf Numbers

POTD Link - https://leetcode.com/problems/sum-root-to-leaf-numbers/description

GitHub Solution Link- https://github.com/anshuahi/LeetCode/blob/main/daily-challenges-2024/15_04_2024.cpp

Approach :
1. pass the prefix value to the root's child, and update it with prefix*10+val
2. if leaf node, add prefix value to ans

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
    int ans;
    void solve(TreeNode *root, int prefVal)
    {
        if (!root)
            return;
        prefVal = prefVal * 10 + root->val;
        if (!root->left && !root->right)
        {
            ans += prefVal;
        }
        solve(root->left, prefVal);
        solve(root->right, prefVal);
    }
    int sumNumbers(TreeNode *root)
    {
        solve(root, 0);
        return ans;
    }
};
