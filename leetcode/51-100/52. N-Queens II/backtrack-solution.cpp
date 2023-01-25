class Solution {
public:
    int res;
    int totalNQueens(int n) {
        if(n == 1) {
            return 1;
        }
        if(n < 4){
            return 0;
        }
        res = 0;
        vector<string> v;
        string s = "";
        for(int i = 0; i < n; i++){
            s += '.';
        }
        for(int i = 0; i < n; i++){
            v.push_back(s);
        }
        
        // vector<vector<string>> res;
        solveNQueensUtil(v, 0, 0);
        
        return res;
    }
    
    bool isSafe(vector<string> v, int x, int y) {
        // int n = 
        for(int i = 0; i < x; i++){
            if(v[i][y] == 'Q'){
                return false;
            }
        }
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
    
    bool solveNQueensUtil(vector<string> &v, int x, int y) {
        if(x == v.size())
            return true;
        if(y == v.size())
            return false;
        if(isSafe(v, x, y)){
            v[x][y] = 'Q';
            bool b = solveNQueensUtil(v, x+1, 0);
            if(b) {
                res++;
            }
            v[x][y] = '.';
            return solveNQueensUtil(v, x, y+1);
        }
        else {
            return solveNQueensUtil(v, x, y+1);
        }
    }
};