/*
LeetCode-POTD: 1544. Make The String Great

POTD Link - https://leetcode.com/problems/make-the-string-great/description

Approach :
    1. iterate the string, and check if s[i] and s[i-1] are same letter but in upper-case or vice-versa, pop ans.
    2. add char to ans

*/

class Solution
{
public:
    string makeGood(string s)
    {
        string ans = "";
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            if (ans.size() && abs(s[i] - ans.back()) == 32)
            {
                ans.pop_back();
            }
            else
            {
                ans += s[i];
            }
        }
        return ans;
    }
};
