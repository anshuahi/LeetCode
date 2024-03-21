#define pb push_back
class Solution {
public:

    void dfs(vector<vector<int>> &gr, vector<bool> &vis, vector<int> &degree, int curr, int &cables, int &nodes){
        if(vis[curr]){
            return;
        }
        vis[curr] = true;
        cables += degree[curr];
        nodes ++;
        for(auto neighbor: gr[curr]){
            dfs(gr, vis, degree, neighbor, cables, nodes);
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> gr(n);
        vector<int> degree(n);
        vector<bool> vis(n);
        for(auto c: connections){
            gr[c[0]].pb(c[1]);
            gr[c[1]].pb(c[0]);
            degree[c[0]]++;
            degree[c[1]]++;
        }

        int components = 0;
        int extraCables = 0;
        for(int i = 0; i < n; i++){
            if(vis[i])
                continue;
            int cables = 0;
            int nodes = 0;
            dfs(gr, vis, degree, i, cables, nodes);
            extraCables += (cables/2 - nodes+1);
            components++;
        }
        if(components - 1 > extraCables)
            return -1;
        return components-1;
    }
};