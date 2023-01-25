class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n,0));
        int left = 0, right = n-1, up = 0, down = n-1;

        int p = 1;
        while(left <= right){
            
            for(int j = left; j <= right; j++){
                v[up][j] = p++;
            }
            up++;
            for(int i = up; i <= down; i++) {
                v[i][right] = p++;
            }
            right--;
            for(int j = right; j >= left; j--){
                v[down][j] = p++;
            }
            down--;
            for(int i = down; i >= up; i--){
                v[i][left] = p++;
            }
            left++;
        }
        
        return v;
    }
};