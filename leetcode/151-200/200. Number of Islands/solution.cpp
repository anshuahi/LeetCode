#define pii pair<int, int>
#define mp make_pair
class Solution {
public:

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int vis[m][n];
        
        memset(vis, 0, sizeof(vis));
        queue<pii> q;
        int sum = 0;
        
        // BFS
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j] && grid[i][j] == '1'){
                    q.push(mp(i, j));
                    int count = 0;
                    while(!q.empty()){
                        pii p = q.front();
                        q.pop();
                        int sr = p.first;
                        int sc = p.second;
                        if(sr < 0 || sc < 0 || sr >= m || sc >= n || grid[sr][sc] == '0' || vis[sr][sc])
                            continue;
                        vis[sr][sc]++;
                        q.push({sr-1, sc});
                        q.push({sr, sc-1});
                        q.push({sr+1, sc});
                        q.push({sr, sc+1});
                    }
                    sum++;
                }
            }
        }
        
        return sum;
    }
};