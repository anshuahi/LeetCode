#define pb push_back
class Solution {
public:
    bool isCycle;
    int ans = 0;
    vector<int> dfs(vector<vector<int>> &gr, int curr, vector<bool> &vis, 
                        vector<bool> &visited, vector<vector<int>> &dp, string &colors){
        if(isCycle){
            return {};
        }
        if(visited[curr]){
            isCycle = true;
            return {};
        }
        if(vis[curr]){
            return dp[curr];
        }
        vis[curr] = true;
        visited[curr] = true;
        vector<int> v(26, 0), u;
        for(auto x: gr[curr]){
            u = dfs(gr, x, vis, visited, dp, colors);
            if(isCycle){
                return {};
            }
            for(int i = 0; i < 26; i++){
                v[i] = max(v[i], u[i]);
                ans = max(ans, v[i]);
            }
        }
        v[colors[curr] - 'a'] ++;
        ans = max(ans, v[colors[curr] - 'a']);
        visited[curr] = false;
        return dp[curr] = v;
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        ans = 0;
        isCycle = false;
        vector<vector<int>> gr(n);
        for(auto edge: edges){
            gr[edge[0]].pb(edge[1]);
        }
        vector<bool> vis(n), visited(n);
        vector<vector<int>> dp(n, vector<int>(26, 0));
        vector<string> v;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dp[i] = dfs(gr, i, vis,visited, dp, colors);
            }
            if(isCycle){
                return -1;
            }
        }
        return ans;
    }
};