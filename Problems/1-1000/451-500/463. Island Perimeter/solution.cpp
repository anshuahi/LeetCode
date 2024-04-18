/*
LeetCode-POTD: 463. Island Perimeter (18_04_2024)

POTD Link - https://leetcode.com/problems/island-perimeter/description/

Approach :
    1. iterate every cell and count its neighbors

*/
class Solution
{
public:
    bool isValid(int i, int j, int n, int m)
    {
        return 0 <= i && i < n && 0 <= j && j < m;
    }
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        vector<int> dirX = {1, -1, 0, 0};
        vector<int> dirY = {0, 0, -1, 1};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j])
                {
                    for (int d = 0; d < 4; d++)
                    {
                        int nbrI = i + dirX[d];
                        int nbrJ = j + dirY[d];
                        if (!isValid(nbrI, nbrJ, n, m) || grid[nbrI][nbrJ] == 0)
                        {
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
