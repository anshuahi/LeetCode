/*
LeetCode-POTD: 2373. Largest Local Values in a Matrix

POTD Link - https://leetcode.com/problems/largest-local-values-in-a-matrix/description/

Approach
    1. brute force
*/
class Solution
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        vector<vector<int>> v;
        for (int i = 0; i < grid.size() - 2; i++)
        {
            vector<int> v1;
            for (int j = 0; j < grid.size() - 2; j++)
            {
                int a = -1;
                for (int x = i; x < i + 3; x++)
                {
                    for (int y = j; y < j + 3; y++)
                    {
                        a = max(a, grid[x][y]);
                    }
                }
                v1.push_back(a);
            }
            v.push_back(v1);
        }

        return v;
    }
};
