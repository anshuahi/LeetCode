#define pii pair<int, int>
#define pb push_back
class Solution {
public:

    bool valid(int i, int j, int n, int m){
        if(i < 0 || j < 0 || i >= n || j >= m){
            return false;
        }
        return true;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pii> q;
        for(int i = 0; i < n; i++){
            if(grid[i][0] == 0){
                q.push({i, 0});
            }
            if(grid[i][m-1] == 0){
                q.push({i, m-1});
            }
        }
        for(int i = 0; i < m; i++){
            if(grid[0][i] == 0){
                q.push({0, i});
            }
            if(grid[n-1][i] == 0){
                q.push({n-1, i});
            }
        }
        vector<int> x = {0, 1, 0, -1};
        vector<int> y = {1, 0, -1, 0};
        
        while(!q.empty()){
            pii p = q.front(); q.pop();
            int i = p.first, j = p.second;
            if(grid[i][j]){
                continue;
            }
            grid[i][j] = 1;
            vis[i][j] = true;
            for(int k = 0; k < 4; k++){
                if(valid(i+x[k], j+ y[k], n, m)){
                    q.push({i+x[k], j+ y[k]});
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0){
                    ans++;
                    q.push({i, j});
                    while(!q.empty()){
                        pii p = q.front(); q.pop();
                        int a = p.first, b = p.second;
                        if(grid[a][b] == 0){
                            grid[a][b] = 1;
                            for(int k = 0; k < 4; k++){
                                if(valid(a+x[k], b+ y[k], n, m)){
                                    q.push({a+x[k], b+ y[k]});
                                }
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};

















