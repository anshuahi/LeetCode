#define pb push_back
#define pii pair<int, int>
#define ppii pair<int, pii>
#define ll long long int
class Solution {
public:

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pii>> ed(n);
        for(auto x: redEdges){
            ed[x[0]].pb({x[1], 0});
        }
        for(auto x: blueEdges){
            ed[x[0]].pb({x[1], 1});
        }
        vector<vector<bool>> vis(2, vector<bool>(n));
        vector<int> ans(n, INT_MAX);
        queue<vector<int>> q;
        // three interger in queue source, value, color
        q.push({0, 0, -1});
        vector<int> f;
        int source, value, color;
        ans[0] = 0;
        // int currLength = 0
        while(!q.empty()){
            f = q.front(); q.pop();
            source = f[0], value = f[1], color = f[2];
            for(auto [node, c]: ed[source]){
                if(!vis[c][node] && c != color){
                    vis[c][node] = true;
                    q.push({node, 1+value, c});
                    if(ans[node] > 1 + value){
                        ans[node] = 1+value;
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(ans[i] == INT_MAX){
                ans[i] = -1;
            }
        }

        return ans;
    }
};
// #GENIUS SOLUTION
