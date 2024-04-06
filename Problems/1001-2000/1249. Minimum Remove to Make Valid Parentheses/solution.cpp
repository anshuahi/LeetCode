/*
LeetCode-POTD: 1249. Minimum Remove to Make Valid Parentheses

POTD Link - https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/

Approach :
1. Use a stack to keep track of valid parentheses
2. if any invalid bracket occurs, mark it false.
*/

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        stack<int> st;
        int n = s.size();
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++)
        {
            if ('a' <= s[i] && s[i] <= 'z')
            {
                vis[i] = true;
            }
            else if (s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                if (!st.empty())
                {
                    vis[i] = true;
                    vis[st.top()] = true;
                    st.pop();
                }
            }
        }
        string p = "";
        for (int i = 0; i < n; i++)
        {
            if (vis[i])
            {
                p += s[i];
            }
        }

        return p;
    }
};
