#define pb push_back
#define M 1000000007
#define ll long long
class Solution {
public:

    int solve(int i, int j, vector<vector<int>> &dp, vector<string>& words, string &target, vector<vector<int>> &freq){
        int n = target.size();
        int m = words[0].size();

        if(j == n){
            return dp[i][j] = 1;
        }

        if(i >= m){
            return dp[i][j] = 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int f = freq[i][target[j]-'a'];
        ll ans = 0;
        ans += 1ll *f * solve(i+1, j+1, dp, words, target, freq) + solve(i+1, j, dp, words, target, freq);
        ans = ans%M;

        return dp[i][j] = ans;
    }

    int numWays(vector<string>& words, string target) {
        int n = target.size();
        int m = words[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        vector<vector<int>> freq(m+1, vector<int>(26, 0));
        for(auto w: words){
            for(int i = 0; i < m; i++){
                freq[i][w[i]-'a']++;
            }
        }

        return solve(0, 0, dp, words, target, freq);
    }
};