class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m = g.size();
        int n = g[0].size();
        
        vector<vector<int> > v(m, vector<int>(n, 0));
        
        if(g[0][0])
            return 0;
        
        v[0][0] = 1;
        
            
        for(int i = 1; i < m; i++){
            if(g[i][0])
                v[i][0] = 0;
            else
                v[i][0] = v[i-1][0];
        }
        
        for(int i = 1; i < n; i++){
            if(g[0][i])
                v[0][i] = 0;
            else
                v[0][i] = v[0][i-1];
        }
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(g[i][j]){
                    v[i][j] = 0;
                }
                else {
                    v[i][j] = v[i-1][j] + v[i][j-1];
                }
            }
        }
        
        // for(int i = 0; i < m; i++) {
        //     for(int j = 0; j < n; j++) {
        //         cout << v[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        return v[m-1][n-1];
    }
};