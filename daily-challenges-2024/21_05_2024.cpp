/*
LeetCode-POTD: 78. Subsets

POTD Link - https://leetcode.com/problems/subsets/description/

Approach
1. try all combinations using backtracking

*/
class Solution
{
public:
    vector<vector<int>> ans;
    void solve(vector<int> &nums, int idx, vector<int> &v)
    {
        if (idx == nums.size())
        {
            ans.push_back(v);
            return;
        }
        v.push_back(nums[idx]);
        solve(nums, idx + 1, v);
        v.pop_back();
        solve(nums, idx + 1, v);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> v;
        solve(nums, 0, v);
        return ans;
    }
};