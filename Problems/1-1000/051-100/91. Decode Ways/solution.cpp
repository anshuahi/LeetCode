class Solution {
public:
    
    int helper(string s, int st, int en, vector<vector<int>> &dp) {
        if(st > en)
            return 1;
        if(s[st] == '0'){
            return dp[st][en] = 0;
        }
        if(st == en){
            return dp[st][st] = 1;
        }
        
        
        if(dp[st][en] != -1){
            return dp[st][en];
        }

        long x = 0;
        
        if(s[st] == '1' || (s[st] == '2' && ('0' <= s[st+1] && s[st+1] <= '6'))){
            return dp[st][en] = helper(s, st+1, en, dp) + helper(s, st+2, en, dp);
        }
        return dp[st][en] =  helper(s, st+1, en, dp);
    }
    
    int numDecodings(string s) {
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int i = 0;
        if(s[i] == '0'){
            return 0;
        }
        return helper(s, i, n-1, dp);
        
        // return dp[0][n-1];
    }
};