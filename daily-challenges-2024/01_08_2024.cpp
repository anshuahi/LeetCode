/*
LeetCode - POTD: 2678. Number of Senior Citizens

POTD Link - https://leetcode.com/problems/number-of-senior-citizens/

GitHub Solution Link- https://github.com/anshuahi/LeetCode/blob/main/daily-challenges-2024/05_08_2024.cpp

Approach
1. extract age from detail, and compare if its greater than 60
*/

class Solution
{
public:
    int countSeniors(vector<string> &details)
    {
        int ans = 0;

        for (auto detail : details)
        {
            int age = stoi(detail.substr(11, 2));
            ans += (age > 60);
        }

        return ans;
    }
};
