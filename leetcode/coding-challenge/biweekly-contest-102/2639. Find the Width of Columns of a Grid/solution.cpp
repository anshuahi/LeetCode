class Solution {
public:
    
    int nums(int &n){
        int x = abs(n);
        if(n == 0)
            return 1;
        int ans = 0;
        while(x > 0){
            ans ++;
            x = x/10;
        }
        
        if(n < 0)
            ans++;
        return ans;
    }
    
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> v;
        int n = grid.size();
        for(int j = 0; j < grid[0].size(); j++){
            int ans = 0;
            for(int i = 0; i < n; i++){
                ans = max(ans, nums(grid[i][j]));
            }
            
            v.push_back(ans);
        }
        
        return v;
    }
};