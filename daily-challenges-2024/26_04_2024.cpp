/*
LeetCode-POTD: 1289. Minimum Falling Path Sum II

POTD Link - https://leetcode.com/problems/minimum-falling-path-sum-ii/description/

Approach :
    1. take min from the last row(except the same column)
    2. update each value, and take the min value from last row

*/

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        vector<vector<int>> dp = grid;
        int n = grid.size(), m = grid[0].size();
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int mn = INT_MAX;
                for (int k = 0; k < m; k++)
                {
                    if (k != j)
                    {
                        mn = min(mn, dp[i - 1][k]);
                    }
                }
                dp[i][j] = mn + grid[i][j];
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < m; i++)
        {
            ans = min(ans, dp.back()[i]);
        }
        return ans;
    }
};
