class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
        }
        for(int i = 0; i < n-1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = 2;
            }
            else {
                dp[i][i+1] = 1;
            }
        }
        for(int l = 3; l <= n; l++){
            for(int i = 0; i < n+1-l; i++){
                if(i+l-1 < n && s[i] == s[i+l-1]){
                    dp[i][i+l-1] = max(dp[i][i+l-1], 2 + dp[i+1][i+l-2]);
                }
                else {
                    dp[i][i+l-1] = max(dp[i+1][i+l-1], dp[i][i+l-2]);
                }
            }
        }
        int ans = 0;
        for(auto x: dp){
            for(auto y: x){
                ans = max(y, ans);
            }
        }

        return ans;
    }
};