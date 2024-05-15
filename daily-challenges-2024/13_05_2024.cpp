/*
LeetCode-POTD: 861. Score After Flipping Matrix

POTD Link - https://leetcode.com/problems/score-after-flipping-matrix/description/

Approach
    1. filp row if first element of the row is zero
    2. flip column if zeros are more than ones
*/

class Solution
{
public:
    int matrixScore(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            if (grid[i][0] == 0)
            {
                for (int j = 0; j < n; j++)
                {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }
        int ans = 0;
        for (int j = 0; j < n; j++)
        {
            int count = 0;
            for (int i = 0; i < m; i++)
            {
                count += grid[i][j];
            }
            count = max(count, m - count);
            ans += pow(2, n - 1 - j) * count;
        }

        return ans;
    }
};
