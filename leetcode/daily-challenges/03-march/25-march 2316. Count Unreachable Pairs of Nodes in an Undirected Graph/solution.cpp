#define pb push_back
#define ll long long int
class Solution {
public:

    void dfs(vector<vector<int>> &gr, int curr, vector<bool> &vis, int &nodes){
        if(vis[curr])
            return;
        vis[curr] = true;
        nodes++;
        for(auto x: gr[curr]){
            dfs(gr, x, vis, nodes);
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> gr(n);
        for(auto ed: edges){
            gr[ed[0]].pb(ed[1]);
            gr[ed[1]].pb(ed[0]);
        }
        vector<bool> vis(n);
        vector<int> v;

        int nodes = 0;
        for(int i = 0; i < n; i++){
            if(vis[i])
                continue;
            nodes = 0;
            dfs(gr,i, vis,nodes);
            v.pb(nodes);
        }

        ll ans = 0;
        for(auto x: v){
            ans += 1ll * x * (n-x);
        }

        return ans/2;
    }
};