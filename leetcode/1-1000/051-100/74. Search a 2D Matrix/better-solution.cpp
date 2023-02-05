class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int target) {
        
        int n = v.size();
        int m = v[0].size();
        
        int st = 0, en = m*n-1;
        int i, j;
        while(st <= en){
            int mid = (st+en)/2;
            i = mid/m, j = mid%m;
            if(v[i][j] == target){
                return true;
            }
            if(v[i][j] < target){
                st = mid+1;
            }
            else {
                en = mid-1;
            }
        }
        
        return false;
    }
};
// Time complexity : O(log(m+n))
// Space complexity : O(1)