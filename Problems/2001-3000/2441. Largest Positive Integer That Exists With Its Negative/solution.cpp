/*
LeetCode-POTD: 2441. Largest Positive Integer That Exists With Its Negative

POTD Link - https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/

Approach
   1. use map, and find if it's negative element exists
*/

class Solution
{
public:
    int findMaxK(vector<int> &v)
    {
        int ans = -1;
        map<int, bool> mp;

        for (auto x : v)
        {
            if (mp.find(-x) != mp.end())
            {
                ans = max(ans, abs(x));
            }
            mp[x] = true;
        }

        return ans;
    }
};
