/*
LeetCode-POTD: 1219. Path with Maximum Gold

POTD Link - https://leetcode.com/problems/path-with-maximum-gold/description

Approach
    1. DFS + backtracking
    2. set grid[i][j] = 0, and add it to the answer
    3. reset grid[i][j] after exploring all possible paths.

*/

class Solution
{
public: // int getMaximumGold(vector<vector<int>>& grid) {
    int maxGold = 0;
    vector<int> roww = {1, -1, 0, 0};
    vector<int> coll = {0, 0, -1, 1};
    int checkIfAllNonZeros(vector<vector<int>> &grid)
    {

        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] != 0)
                    count += grid[i][j];
                else
                    return 0;
            }
        }

        return count;
    }

    void backtrack(vector<vector<int>> &grid, int x, int y, int count)
    {
        if (x < 0 || x >= grid.size() || y >= grid[0].size() || y < 0)
            return;

        if (grid[x][y])
        {
            int curr = grid[x][y];
            grid[x][y] = 0;
            count += curr;
            maxGold = max(maxGold, count);
            for (int i = 0; i < 4; i++)
            {
                int newX = x + roww[i];
                int newY = y + coll[i];
                backtrack(grid, newX, newY, count);
            }
            grid[x][y] = curr;
        }
    }

    int getMaximumGold(vector<vector<int>> &grid)
    {
        int count = checkIfAllNonZeros(grid);
        if (count)
            return count;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j])
                {
                    backtrack(grid, i, j, 0);
                }
            }
        }

        return maxGold;
    }
};