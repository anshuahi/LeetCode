/*

LeetCode-POTD: 58. Length of Last Word

POTD Link - https://leetcode.com/problems/length-of-last-word/description/

Approach :
    1. remove the whitespace at the end
    2. count the consecutive chars from the end.

*/

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        while (s.size() > 0 && s.back() == ' ')
        {
            s.pop_back();
        }
        int i = s.size() - 1;
        int ans = 0;
        while (i >= 0)
        {
            if (s[i] == ' ')
            {
                break;
            }
            ans++;
            i--;
        }
        return ans;
    }
};
