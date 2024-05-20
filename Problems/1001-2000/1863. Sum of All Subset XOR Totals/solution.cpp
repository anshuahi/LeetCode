/*
LeetCode-POTD: 1863. Sum of All Subset XOR Totals

POTD Link - https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/

Approach
    1. try all combinations as n <= 12, total 2^12 possibilities

*/

class Solution
{
public:
    int ans = 0;
    void traverse(vector<int> &nums, int idx, int curr)
    {
        if (idx >= nums.size())
        {
            ans += curr;
            return;
        }
        traverse(nums, idx + 1, curr);
        traverse(nums, idx + 1, curr ^ nums[idx]);
    }

    int subsetXORSum(vector<int> &nums)
    {
        ans = 0;
        int n = nums.size();
        traverse(nums, 0, 0);
        return ans;
    }
};
