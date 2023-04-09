#define pb push_back
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> fromCapital(n), toCapital(n);
        for(auto c: connections){
            fromCapital[c[0]].pb(c[1]);
            toCapital[c[1]].pb(c[0]);
        }
        vector<bool> vis(n);
        int ans = 0;
        queue<int> q;
        q.push(0);

        while(!q.empty()) {
            int t = q.front();
            q.pop();
            if(vis[t])
                continue;
            vis[t] = true;
            
            for(auto x: toCapital[t]){
                q.push(x);
            }

            for(auto x: fromCapital[t]){
                if(vis[x]){
                    continue;
                }
                ans++;
                q.push(x);
            }
        }
        return ans;
    }
};
// GENIUS

