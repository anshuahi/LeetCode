#define pb push_back
#define pii pair<int, int>
class Solution {
public:

    void dfs(vector<vector<pii>> &gr, int curr, vector<bool> &vis, int &ans){
        if(vis[curr])
            return;
        vis[curr] = true;
        for(auto [neighbor, dist]: gr[curr]){
            ans = min(ans, dist);
            dfs(gr, neighbor, vis, ans);
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pii>> gr(n+1);
        vector<bool> vis(n+1), last(n+1);
        for(auto r: roads){
            gr[r[0]].pb({r[1], r[2]});
            gr[r[1]].pb({r[0], r[2]});
        }
        int ans = INT_MAX;
        dfs(gr, 1, vis, ans);
        return ans;
    }
};