class Solution {
public:
    
    int count(int n, vector<int> &dp){
        if(n <= 0){
            return 1;
        }
        
        if(dp[n] != -1)
            return dp[n];
        long x = 0;
        for(int i = 1; i <= n;i++){
            x += count(i-1, dp) * count(n-i, dp);
        }
        
        return dp[n] = x;
    }
    
    int numTrees(int n) {
        vector<int> dp(n+1, -1);
        dp[0] = 1;
        dp[1] = 1;
        return count(n, dp);
    }
};