#define pb push_back
class Solution {
public:

    int min(int a, int b){
        if(a < b)
            return a;
        return b;
    }

    int parti(string s, vector<vector<int>> &g, int i) {
        if(i == s.size()){
            return 0;
        }
        int ans, p;
        // vector<string> v;
        // string a;
        int m = s.size()-i-1;
        for(auto x: g[i]){
            p = parti(s, g, x+1);
            m = min(m, 1 + p);
        }

        return m;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> c(n+1, 0);
        // cout << n << endl;
        for(int i = 0; i <= n; i++){
            c[i] = i-1;
        }

        for(int i = 0; i < n; i++){
            // odd length
            int j = i, k = i;
            while(j >= 0 && k < n && s[j] == s[k]){
                c[k+1] = min(c[j]+1, c[k+1]);
                j --, k++;
            }
            // even length
            j = i, k = i+1;
            while(j >= 0 && k < n && s[j] == s[k]){
                c[k+1] = min(c[j]+1, c[k+1]);
                j --, k++;
            }
        }

        return c[n];
    }
};
