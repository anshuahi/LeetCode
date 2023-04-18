class Solution {
public:

    int solve(vector<vector<int>>& piles, int i, int k, vector<vector<int>>& dp){
        if(dp[i][k])
            return dp[i][k];
        int n = piles.size();
        if(i == n || k == 0){
            return dp[i][k] = 0;
        }
        int ans = solve(piles, i+1, k, dp);
        int sum = 0;
        for(int j = 0; j < k && j < piles[i].size(); j++){
            sum += piles[i][j];
            ans = max(ans, solve(piles, i+1, k-j-1, dp)+ sum);
        }

        return dp[i][k] = ans;
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        return solve(piles, 0, k, dp);
    }
};