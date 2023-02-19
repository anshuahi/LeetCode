#define pii pair<int, int>
#define pb push_back

class Solution {
public:
    
    bool isValid(int i, int j, int n, int m){
        if(i < 0 || j < 0 || i >= n || j >= m){
            return false;
        }
        return true;
    }
    
    void dfs(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>> &dp, int val){
        if(!isValid(i, j, n, m) || grid[i][j] == 0|| grid[i][j] == 2){
            return;
        }
        if(dp[i][j] > val){
            dp[i][j] = val;
            dfs(i-1, j, n, m, grid, dp, 1+val);
            dfs(i+1, j, n, m, grid, dp, 1+val);
            dfs(i, j-1, n, m, grid, dp, 1+val);
            dfs(i, j+1, n, m, grid, dp, 1+val);
        }
    }
    
    
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX/2));
        vector<pii> p, q;
        for(int i =0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    dp[i][j] = 0;
                    dfs(i-1, j, n, m, grid, dp, 1);
                    dfs(i+1, j, n, m, grid, dp, 1);
                    dfs(i, j-1, n, m, grid, dp, 1);
                    dfs(i, j+1, n, m, grid, dp, 1);
                }
            }
        }
        int ans = 0;
        for(int i =0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    if(dp[i][j] == INT_MAX/2)
                        return -1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};