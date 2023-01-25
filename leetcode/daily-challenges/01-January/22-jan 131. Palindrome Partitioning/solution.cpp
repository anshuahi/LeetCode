#define pb push_back

class Solution {
public:


    void dfs(string s, int i, vector<string> &v, vector<vector<string>> &ans){
        if(i == s.size()){
            ans.pb(v);
            return;
        }
    }


    vector<vector<string>> parti(string s, vector<vector<int>> &g, int i) {
        if(i == s.size()){
            return {{}};
        }
        vector<vector<string>> ans, p;
        // vector<string> v;
        string a;
        for(auto x: g[i]){
            p = parti(s, g, x+1);
            a = s.substr(i, x-i+1);
            for(auto p1: p){
                p1.insert(p1.begin(), a);
                ans.pb(p1);
            }
        }

        return ans;
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        vector<vector<int>> g(n);
        for(int i = 0; i < n; i++){
            g[i].pb(i);
            // odd length palindrome
            int j = 1, k;
            while(i-j >= 0 && i+j < n){
                if(s[i-j] == s[i+j]){
                    g[i-j].pb(i+j);
                }
                else {
                    break;
                }
                j++;
            }
            // even length palindrome
            j = i, k = i+1;
            while(j >= 0 && k < n){
                if(s[j] == s[k]){
                    g[j].pb(k);
                }
                else {
                    break;
                }
                j--,k++;
            }
        }

        vector<vector<string>> ans = parti(s, g, 0);
        return ans;
    }
};
