class Solution {
public:

    void dfs(vector<int>& edges, vector<bool> &vis, int curr, set<int> &v){
        if(curr == -1){
            return;
        }
        if(vis[curr]){
            v.insert(curr);
            return;
        }
        vis[curr] = true;
        if(edges[curr] == -1)
            return;
        dfs(edges, vis, edges[curr], v);
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> vis(n), visited(n);
        set<int> v;
        for(int i = 0; i < n; i++){
            if(!vis[i])
                dfs(edges, vis, i, v);
        }

        int ans = -1;
        int z = 1;
        vector<int> mp(n, -1);
        int z1 = z;
        for(int x = 0; x < n; x++){
            int len = 1;
            if(visited[x])
                continue;
            visited[x] = true;
            int p = edges[x];
            if(p == -1 || visited[p]){
                continue;
            }
            z1 = z;
            mp[x] = ++z;
            while(true){
                if(mp[p] != -1){
                    if(mp[p] <= z1){
                        break;
                    }
                    ans = max(ans, z - mp[p]+1);
                    break;
                }
                visited[p] = true;
                mp[p] = ++z;
                p = edges[p];
                if(p == -1){
                    break;
                }
            }
        }

        return ans;
    }
};