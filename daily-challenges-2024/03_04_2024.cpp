/*
LeetCode-POTD: 79. Word Search

POTD Link - https://leetcode.com/problems/word-search/description

*Approach* :     
    1. use DFS on all four directions, 
    2. if it doesn't match the character, backtrack it.
*/

class Solution {
public:
    vector<int> x = {0, 0, -1, 1};
    vector<int> y = {-1, 1, 0, 0};
    bool dfs(vector<vector<char>>& board, string &word, int idx, int i, int j){
        int n = board.size(), m = board[0].size();
        if(idx == word.size()){
            return true;
        }
        if(i < 0 || j < 0 || i >= n || j >= m || word[idx] != board[i][j]){
            return false;
        }

        bool ans = 0;
        char c = board[i][j];
        board[i][j] = '#';
        for(int k = 0; k < 4; k++){
            if(dfs(board, word, idx+1, i+x[k], j+y[k])){
                return true;
            }
        }
        // backtrack
        board[i][j] = c;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(dfs(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
};
