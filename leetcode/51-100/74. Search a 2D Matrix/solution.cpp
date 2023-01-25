class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int t) {
        
        int n = v.size();
        int m = v[0].size();
        
        int i = n-1, j = 0; // start from bottom left corner
        while(i >= 0 && j < m){
            int x = v[i][j];
            if(x == t)      // if found return true
                return true;
            if(x > t){      // if the current element is greater than our target is on top side of matrix
                i--;
            }
            else {          // if the current element is lesser than our target is on right side of matrix
                j++;
            }
        }
        
        return false;
    }
};
// Time complexity : O(m+n)
// Space complexity : O(1)