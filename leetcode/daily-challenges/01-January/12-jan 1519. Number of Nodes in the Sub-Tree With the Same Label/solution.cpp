class Solution {
public:

    vector<int> dfs(int node, vector<vector<int>>& gr, string &s, int parent, vector<int> &ans){
        vector<int> f(26, 0), v;
        f[s[node]-'a'] = 1;

        for(auto x: gr[node]){
            if(parent != x){
                v = dfs(x, gr, s, node, ans);
                for(int i1 = 0; i1 < 26; i1++){
                    f[i1] += v[i1];
                }
            }
        }
        ans[node] = f[s[node]-'a'];
        return f;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> ans(n, 0);
        vector<vector<int>> gr(n);
        for(auto& e: edges){
            gr[e[0]].push_back(e[1]);
            gr[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n, false);
        dfs(0, gr, labels, -1, ans);
        return ans;
    }
};
// GENIUS