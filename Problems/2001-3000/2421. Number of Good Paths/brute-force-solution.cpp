#define pb push_back

// pretty good approach but not efficient
class Solution {
public:
    int ans;
    // traverse from each node to all possible paths where the value <= value of parent node
    /*
    start from a node and traverse to its neighbors, which have a lower value than the node.
    From the neighbors, we move to their neighbors. If we find another node with a value similar to the start node, 
    we have one good path.
    */
    void dfs(vector<vector<int>> &gr, vector<int>& v, int i, int st, int val, vector<bool> &vis){
        if(v[i] > val || vis[i])
            return;
        if(v[i] == val){
            ans++;
        }
        vis[i] = true;
        for(auto x: gr[i]){
            dfs(gr, v, x, i, val, vis);
        }
    }
    
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& ed) {
        int n = vals.size();
        vector<vector<int>> gr(n);
        ans = 0;
        for(auto e: ed){
            gr[e[0]].pb(e[1]);
            gr[e[1]].pb(e[0]);
        }
        vector<bool> vis(n, false);
        
        for(int i = 0; i < n; i++) {
            fill(vis.begin(), vis.end(), false);
            dfs(gr, vals, i, i, vals[i], vis);  // traverse the dfs for each node as root
        }
        
        return (ans+n)/2;
    }
};