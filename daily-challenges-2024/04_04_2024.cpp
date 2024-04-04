/*
LeetCode-POTD: 1614. Maximum Nesting Depth of the Parentheses

POTD Link - https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/

*Approach* :
    1. increase depth when *(*, decrease depth when *)*
    2. store the maximum depth in answer

*/

class Solution
{
public:
    int maxDepth(string s)
    {
        int ans = 0;
        int depth = 0;
        for (auto c : s)
        {
            if (c == '(')
            {
                depth++;
            }
            else if (c == ')')
            {
                depth--;
            }
            ans = max(ans, depth);
        }
        return ans;
    }
};
