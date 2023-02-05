class Solution {
public:
    
    bool check(vector<vector<char>>& board, vector<vector<bool>>& vis, string word, int ind, int i, int j){
        
        if(ind == word.length())
            return true;
        
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || vis[i][j] || word[ind] != board[i][j]){
            return false;
        }
        
        vis[i][j] = true;
        
        if(check(board, vis, word, ind + 1, i - 1, j)){
            return true;
        }
        if(check(board, vis, word, ind + 1, i, j - 1)){
            return true;
        }
        if(check(board, vis, word, ind + 1, i + 1, j)){
            return true;
        }
        if(check(board, vis, word, ind + 1, i, j + 1)){
            return true;
        }
        
        vis[i][j] = false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0]){
                    if(check(board, vis, word, 0, i, j)){
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};