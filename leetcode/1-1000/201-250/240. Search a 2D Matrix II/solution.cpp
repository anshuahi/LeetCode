class Solution {
public:
        
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int m = mat.size();
        int n = mat[0].size();
        int i = m-1, j = 0;
        
        while(i >= 0 && j < n){
            if(mat[i][j] == t){
                return true;
            }
            else if(mat[i][j] < t){
                j++;
            }
            else {
                i--;
            }
        }
        return false;
    }
};