class Solution {
public:
    
    bool checkRow(vector<vector<char>>& board, int i, int j) {
        for(int k = 0; k < 9; k++){
            if(i != k && board[i][j] == board[k][j])
                return false;
        }
        return true;
    }
    
    bool checkColumn(vector<vector<char>>& board, int i, int j) {
        for(int k = 0; k < 9; k++){
            if(j != k && board[i][j] == board[i][k])
                return false;
        }
        return true;
    }    
    
    bool checkBox(vector<vector<char>>& board, int i, int j) {
        int x = i/3, y = j/3;
        for(int p = 0; p < 3; p++){
            for(int q = 0; q < 3; q++) {
                if(i != x*3+p && j != y*3+q && board[i][j] == board[x*3+p][y*3+q])
                    return false;
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<char>>& board, int i, int j){
        return checkRow(board, i, j) && checkColumn(board, i, j) && checkBox(board, i, j);
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.')
                    continue;
                if(!isValid(board, i, j))
                    return false;
            }
        }
        
        return true;
    }
};