#define pb push_back

class Solution {
public:
    int dfs(int v, vector<vector<int>> &g, int &ans, string &s) {
        vector <int> cand;
        for (int u : g[v]) {
            cand.push_back(dfs(u, g, ans, s));
        }
        int mx1 = -1;
        int mx2 = -1;
        int i_mx1 = -1;
        for (int i = 0; i < cand.size(); i++) {
            if (cand[i] > mx1 and s[g[v][i]] != s[v]) {
                mx2 = mx1;
                mx1 = cand[i];
                i_mx1 = i;
            }
        }
        for (int i = 0; i < cand.size(); i++) {
            if (cand[i] > mx2 and s[g[v][i]] != s[v] and i != i_mx1) {
                mx2 = cand[i];
            }
        }
        ans = max(ans, 1); 
        if (mx1 != -1 and mx2 == -1) ans = max(ans,1+mx1); 
        else if (mx1 == -1 and mx2 != -1) ans = max(ans,1+mx2); 
        else if (mx1 != -1 and mx2 != -1) ans = max(ans,1+mx1+mx2); 
        int res = 1; 
        res = max(res, 1+mx1);
        res = max(res, 1+mx2);
        return res; 
    }
    int longestPath(vector<int>& par, string s) {
        int n = par.size();
        vector<vector<int>> g(n);
        for (int i = 1; i < n; i++) {
            g[par[i]].push_back(i);
        }
        int ans = 0;
        dfs(0, g, ans, s);
        return ans; 
    }
};