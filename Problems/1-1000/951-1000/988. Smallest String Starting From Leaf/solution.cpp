/*
LeetCode-POTD: 988. Smallest String Starting From Leaf

POTD Link - https://leetcode.com/problems/smallest-string-starting-from-leaf/description/

Approach :
    1. recursively generate all possible string
    2. store the smallest string

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
    string ans;
    void solve(TreeNode *root, string s)
    {
        if (!root)
            return;
        char ch = ('a' + root->val);
        s += ch;
        if (!root->left && !root->right)
        {
            reverse(s.begin(), s.end());
            ans = (ans == "") ? s : min(ans, s);
            return;
        }
        solve(root->left, s);
        solve(root->right, s);
    }
    string smallestFromLeaf(TreeNode *root)
    {
        if (!root)
        {
            return "";
        }
        solve(root, "");
        return ans;
    }
};
