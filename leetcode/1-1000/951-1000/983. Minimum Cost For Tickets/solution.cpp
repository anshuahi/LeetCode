class Solution {
public:

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        days.push_back(0);
        sort(days.begin(), days.end());
        int n = days.size();
        vector<int> dp(n);
        int min3 = min(costs[0], min(costs[1], costs[2]));
        dp[1] = min3;

        for(int i = 1; i < n; i++){
            dp[i] = min3 + dp[i-1];
            int j = i-1;
            while(j > 0 && days[i] - days[j] < 7){
                j--;
            }
            dp[i] = min(dp[i], costs[1] + dp[j]);
            j = i-1;
            while(j > 0 && days[i] - days[j] < 30){
                j--;
            }
            dp[i] = min(dp[i], costs[2] + dp[j]);
        }

        return dp[n-1];
    }
};