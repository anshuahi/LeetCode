/*
LeetCode-POTD: 2597. The Number of Beautiful Subsets

POTD Link - https://leetcode.com/problems/the-number-of-beautiful-subsets/description/

*/
class Solution
{
public:
    int countSubsets(vector<int> &nums, int diff, int idx, int prev)
    {
        if (idx == nums.size())
            return 1;

        int skip = countSubsets(nums, diff, idx + 1, prev);
        int take = 0;
        if (abs(nums[idx] - prev) != diff)
        {
            take = countSubsets(nums, diff, idx + 1, nums[idx]);
        }

        return skip + take;
    }
    int beautifulSubsets(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        return countSubsets(nums, k, 0, -2000) - 1;
    }
};