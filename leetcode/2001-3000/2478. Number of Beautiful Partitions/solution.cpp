#define M 1000000007

class Solution {
public:

    int count(int i, int k, string &s, vector<vector<int>> &dp, int &mn){
        if(i == s.size()){
            return dp[i][k] = 0;
        }
        if(k == 0){
            return dp[i][k] = 0;
        }
        if(s.size() - i < k*mn){
            return dp[i][k] = 0;
        }
        if(dp[i][k] != -1){
            return dp[i][k];
        }
        if(s[i] == '1' || s[i] == '4' || s[i] == '0' || s[i] == '6' || s[i] == '8' || s[i] == '9'){
            return dp[i][k] = 0;
        }
        if(k == 1){
            if(s.size() - i < mn){
                return dp[i][k] = 0;
            }
            return dp[i][k] = 1;
        }
        int ans = 0;
        for(int j = i; j < s.size(); j++){
            if(j - i + 1 < mn){
                continue;
            }
            if(s[j] == '1' || s[j] == '4' || s[j] == '0' || s[j] == '6' || s[j] == '8' || s[j] == '9'){
                int z= count(j+1, k-1, s, dp, mn);
                ans += z%M;
                ans %= M;
            }

        }

        return dp[i][k] = ans%M;
    }

    int beautifulPartitions(string s, int k, int minLength) {
        int n = s.size();
        int last = s[n-1]-'0';
        if(last == 2 || last == 3 || last == 5 || last == 7 || n < k*minLength ){
            return 0;
        }

        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        int x = count(0, k, s,dp, minLength);
        return x;

    }
};