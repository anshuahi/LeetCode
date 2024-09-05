/*
LeetCode-POTD: 2678. Number of Senior Citizens

POTD Link - https://leetcode.com/problems/find-missing-observations/description/

GitHub Solution Link- https://github.com/anshuahi/LeetCode/blob/main/daily-challenges-2024/05_09_2024.cpp

Approach
1. calculate the remaining sum from m*mean-array_sum
2. create an answer array of length, and update it based on the remaining sum,
3. if rem > 0, increase it up to 6 else reduce it to 1

*/
class Solution
{
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        vector<int> obs(n, mean);
        int j = 0;
        int rem = 0;
        for (auto x : rolls)
            rem += (mean - x);

        while (rem != 0 && j < n)
        {
            if (rem > 0)
            {
                int newVal = min(rem, 6 - obs[j]);
                obs[j++] += newVal;
                rem -= newVal;
            }
            else
            {
                int newVal = min(abs(rem), obs[j] - 1);
                obs[j++] -= newVal;
                rem += newVal;
            }
        }
        if (rem != 0)
            obs.clear();
        return obs;
    }
};