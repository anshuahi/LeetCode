class NumMatrix {
public:
    vector<vector<int>> v;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        v.resize(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i + j == 0) {
                    v[i][j] = matrix[i][j];
                }
                else if(i == 0) {
                    v[i][j] = matrix[i][j] + v[i][j-1];
                }
                else if(j == 0) {
                    v[i][j] = matrix[i][j] + v[i-1][j];
                }
                else {
                    v[i][j] = matrix[i][j] + v[i-1][j] + v[i][j-1] - v[i-1][j-1];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int x = v[row2][col2];
        
        if(row1 + col1 == 0)
            return x;
        if(row1 == 0)
            return x - v[row2][col1-1];
        
        if(col1 == 0)
            return x - v[row1-1][col2];
        return x - v[row2][col1-1] - v[row1-1][col2] + v[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */