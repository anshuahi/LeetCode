class Solution {
public:
    bool isSafe(vector<string> v, int x, int y) {
        
        // check row
        for(int i = 0; i < x; i++){
            if(v[i][y] == 'Q'){
                return false;
            }
        }

        // check column
        for(int i = 0; i < y; i++){
            if(v[x][i] == 'Q'){
                return false;
            }
        }
        
        // Diagonals
        for(int i = x, j = y; i >= 0 && j >= 0; i--, j--){
            if(v[i][j] == 'Q')
                return false;
        }
        
        for(int i = x, j = y; i >= 0 && j < v.size(); i--, j++){
            if(v[i][j] == 'Q')
                return false;
        }
        
        return true;
    }
    
    bool solveNQueensUtil(vector<string> &v, vector<vector<string>> &res, int x, int y) {
        if(x == v.size())
            return true;
        if(y == v.size())
            return false;
        if(isSafe(v, x, y)){
            v[x][y] = 'Q';
            bool b = solveNQueensUtil(v, res, x+1, 0);
            if(b) {
                res.push_back(v);
            }
            // backtrack
            v[x][y] = '.';
            return solveNQueensUtil(v, res, x, y+1);
        }
        else {
            return solveNQueensUtil(v, res, x, y+1);
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        if(n == 1) {
            return {{"Q"}};
        }
        if(n < 4){
            return {};
        }
        
        vector<string> v;
        string s = "";
        for(int i = 0; i < n; i++){
            s += '.';
        }
        for(int i = 0; i < n; i++){
            v.push_back(s);
        }
        
        vector<vector<string>> res;
        solveNQueensUtil(v, res, 0, 0);
        
        return res;
        
    }
};