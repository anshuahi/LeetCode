#define pb push_back
#define pii pair<int, int>
#define ppii pair<int, pii>
class Solution {
public:

    bool isValid(int i, int j, int n){
        if(i < 0 || j < 0 || i >= n || j >= n){
            return false;
        }
        return true;
    }

    int maxDistance(vector<vector<int>>& g) {
        int n = g.size();
        // int m = g[0].size()
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        priority_queue<ppii, vector<ppii>, greater<ppii>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(g[i][j] == 1){
                    dp[i][j] = 0;
                    q.push({0, {i, j}});
                }
            }
        }
        int x, y, val, i, j;
        while(!q.empty()){
            ppii p = q.top();
            q.pop();
            val = p.first;
            x = p.second.first, y = p.second.second;
            i = x-1, j = y;
            if(isValid(i, j, n)){
                if(dp[i][j] > 1 + val){
                    dp[i][j] = 1+val;
                    q.push({1+val, {i, j}});
                }
            }
            i = x+1, j = y;
            if(isValid(i, j, n)){
                if(dp[i][j] > 1 + val){
                    dp[i][j] = 1+val;
                    q.push({1+val, {i, j}});
                }
            }
            i = x, j = y-1;
            if(isValid(i, j, n)){
                if(dp[i][j] > 1 + val){
                    dp[i][j] = 1+val;
                    q.push({1+val, {i, j}});
                }
            }
            i = x, j = y+1;
            if(isValid(i, j, n)){
                if(dp[i][j] > 1 + val){
                    dp[i][j] = 1+val;
                    q.push({1+val, {i, j}});
                }
            }
        }

        int ans = -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                // cout << dp[i][j] << " ";
                if(g[i][j] == 0){
                    ans = max(ans, dp[i][j]);
                }
            }
            // cout << endl;
        }
        return ans == INT_MAX? -1: ans;
    }
};
