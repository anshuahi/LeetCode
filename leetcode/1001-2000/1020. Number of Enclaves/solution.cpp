#define pii pair<int, int>
class Solution {
public:
    bool valid(int i, int j, int n, int m){
        if(i < 0 || j < 0 || i >= n || j >= m){
            return false;
        }
        return true;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pii> q;
        for(int i = 0; i < n; i++){
            if(grid[i][0] == 1){
                q.push({i, 0});
            }
            if(grid[i][m-1] == 1){
                q.push({i, m-1});
            }
        }
        for(int i = 0; i < m; i++){
            if(grid[0][i] == 1){
                q.push({0, i});
            }
            if(grid[n-1][i] == 1){
                q.push({n-1, i});
            }
        }
        vector<int> x = {0, 1, 0, -1};
        vector<int> y = {1, 0, -1, 0};
        
        while(!q.empty()){
            pii p = q.front(); q.pop();
            int i = p.first, j = p.second;
            if(!grid[i][j]){
                continue;
            }
            grid[i][j] = 0;
            for(int k = 0; k < 4; k++){
                if(valid(i+x[k], j+ y[k], n, m)){
                    q.push({i+x[k], j+ y[k]});
                }
            }
        }
        int ans = 0;
        for(auto g: grid){
            for(auto a: g){
                ans += a;
            }
        }

        return ans;
    }
};