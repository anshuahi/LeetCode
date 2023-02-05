#define pii pair<int, int>
#define pb push_back

class Solution {
public:
    void setZeroes(vector<vector<int>>& g) {
        vector<pii> v;
        int n = g.size();
        int m = g[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(g[i][j] == 0){
                    v.pb({i, j});
                }
            }
        }

        for(auto p: v){
            for(int i = 0; i < n; i++){
                g[i][p.second] = 0;
            }
            for(int i = 0; i < m; i++){
                g[p.first][i] = 0;
            }
        }
    }
};