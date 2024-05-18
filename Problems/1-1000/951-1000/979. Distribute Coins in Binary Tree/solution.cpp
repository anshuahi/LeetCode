/*
LeetCode-POTD: 979. Distribute Coins in Binary Tree

POTD Link - https://leetcode.com/problems/distribute-coins-in-binary-tree/description/

Approach
    1. Calculate the number of moves needed to distribute coins in each of the subtrees, i.e. abs(total coins - number of nodes)

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
#define pii pair<int, int>
class Solution
{
public:
    int ans = 0;
    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;

        int l = dfs(root->left);
        int r = dfs(root->right);
        ans += abs(l) + abs(r);
        return root->val - 1 + l + r;
    }
    int distributeCoins(TreeNode *root)
    {
        ans = 0;
        dfs(root);
        return ans;
    }
};
