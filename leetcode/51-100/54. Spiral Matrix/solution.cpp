class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int n = matrix.size();
        int m = matrix[0].size();
    
        int left = 0, right = m-1, up = 0, down = n-1;

        int p = 1;
        while(left <= right && up <= down){
            
            for(int j = left; j <= right; j++){
                v.push_back(matrix[up][j]);
            }
            up++;
            for(int i = up; i <= down; i++) {
                v.push_back(matrix[i][right]);
            }
            right--;
            for(int j = right; j >= left && up <= down; j--){
                v.push_back(matrix[down][j]);
            }
            down--;
            for(int i = down; i >= up && left <= right; i--){
                v.push_back(matrix[i][left]);
            }
            left++;
        }
        
        return v;
    }
};