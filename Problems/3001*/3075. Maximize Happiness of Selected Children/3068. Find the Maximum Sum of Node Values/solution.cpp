/*
LeetCode-POTD: 3068. Find the Maximum Sum of Node Values

POTD Link - https://leetcode.com/problems/find-the-maximum-sum-of-node-values/description/

Approach
    1. calculate the difference (nums[i] XOR k - nums[i])
    2. Sort the diff array, in descending order
    3. take the pair, if the pair sum is positive.

*/
class Solution
{
public:
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
    {
        int n = nums.size();
        std::vector<int> diff(n);
        long sum = 0;

        for (int i = 0; i < n; ++i)
        {
            diff[i] = (nums[i] ^ k) - nums[i];
            sum += nums[i];
        }

        std::sort(diff.begin(), diff.end(), std::greater<int>());

        for (int i = 0; i < n; i += 2)
        {
            if (i + 1 == n)
                return sum;
            int pair = diff[i] + diff[i + 1];
            if (pair > 0)
                sum += pair;
        }

        return sum;
    }
};
