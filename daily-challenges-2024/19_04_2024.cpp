/*
LeetCode-POTD: 200. Number of Islands

POTD Link - https://leetcode.com/problems/number-of-islands/description/

GitHub Solution Link- https://github.com/anshuahi/LeetCode/blob/main/daily-challenges-2024/19_04_2024.cpp

Approach :
1. iterate all the cells with land, use DFS/BFS, and mark its neighbors as visited.
2. count the islands

*/

//  using DFS
#define pii pair<int, int>
#define mp make_pair
class Solution
{
public:
    void dfs(vector<vector<char>> &grid, int i, int j, vector<vector<bool>> &vis)
    {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0' || vis[i][j])
            return;
        vis[i][j] = true;
        dfs(grid, i - 1, j, vis);
        dfs(grid, i + 1, j, vis);
        dfs(grid, i, j - 1, vis);
        dfs(grid, i, j + 1, vis);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int numOfIslands = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    dfs(grid, i, j, vis);
                    numOfIslands++;
                }
            }
        }

        return numOfIslands;
    }
};

// Using BFS
#define pii pair<int, int>
#define mp make_pair
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int vis[m][n];

        memset(vis, 0, sizeof(vis));
        queue<pii> q;
        int sum = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    q.push(mp(i, j));
                    int count = 0;
                    while (!q.empty())
                    {
                        pii p = q.front();
                        q.pop();
                        int sr = p.first;
                        int sc = p.second;
                        if (sr < 0 || sc < 0 || sr >= m || sc >= n ||
                            grid[sr][sc] == '0' || vis[sr][sc])
                            continue;
                        vis[sr][sc] = 1;
                        q.push({sr - 1, sc});
                        q.push({sr, sc - 1});
                        q.push({sr + 1, sc});
                        q.push({sr, sc + 1});
                    }
                    sum++;
                }
            }
        }

        return sum;
    }
};
