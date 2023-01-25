class Solution {
public:
    int rob(vector<int>& v) {
        int n = v.size();
        vector<int> dp(n+1, 0);
        dp[1] = v[0];
        
        for(int i = 2; i <= n; i++){
            dp[i] = max(dp[i-1], dp[i-2] + v[i-1]);
        }
        
        return dp[n];
    }
};