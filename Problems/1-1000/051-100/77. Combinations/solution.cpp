class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> A[k][n];
        vector<int> p;
        for(int i = 0; i < k; i++) {
            for(int j = i; j < n; j++) {
                if(j - i > n - k)
                    continue;
                if(i == 0 && j == 0) {
                    A[i][j] = {{1}};
                }
                else if(i == 0) {
                    A[i][j] = A[i][j-1];
                    A[i][j].push_back({j+1});
                }
                else if(i == j){
                    A[i][j] = A[i-1][j-1];
                    A[i][j][0].push_back(j+1);
                }
                else if(j > i) {
                    vector<vector<int>> v = A[i-1][j-1];
                    A[i][j] = A[i][j-1];
                    
                    for(int k = 0; k < v.size(); k++){
                        p = v[k];
                        p.push_back(j+1);
                        A[i][j].push_back(p);
                    }
                }
            }
        }
        
        
        return A[k-1][n-1];
    }
};