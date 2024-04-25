/*
LeetCode-POTD: 2370. Longest Ideal Subsequence

POTD Link - https://leetcode.com/problems/longest-ideal-subsequence/description/

GitHub Solution Link- https://github.com/anshuahi/LeetCode/blob/main/daily-challenges-2024/25_04_2024.cpp

Approach :
    1. for each char, iterate through all 26 chars, let count = dp[current]
    2. If the difference is <= k, take the maximum value of iterative char from dp, and store it in the variable count
    3. store dp[current] = count

*/

class Solution
{
public:
    int longestIdealString(string s, int k)
    {
        vector<int> dp(26, 0);
        int ans = 1;
        for (int i = 0; i < s.size(); i++)
        {
            int idx = s[i] - 'a';
            int count = dp[idx];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                if (abs(ch - s[i]) <= k)
                {
                    count = max(count, 1 + dp[ch - 'a']);
                }
            }
            ans = max(ans, count);
            dp[idx] = count;
        }
        return ans;
    }
};
