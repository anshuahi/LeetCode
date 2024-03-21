#define pb push_back
#define M 1000000007

class Solution {
public:
    int dp[102][102][102];
    int findProfitScheme(int n, int minProfit, vector<int>& group, vector<int>& profit, int k, int i, int j){
        if(k == group.size()){
            if(i <= n && j >= minProfit)
                return 1;
            return 0;
        }
        if(n < i)
            return 0;
        if(dp[k][i][j] != -1){
            return dp[k][i][j];
        }

        int inc = 0, notInc = 0;
        inc = findProfitScheme(n, minProfit, group, profit, k+1, i+group[k], min(minProfit, j+profit[k]));
        notInc = findProfitScheme(n, minProfit, group, profit, k+1, i, j);

        return dp[k][i][j] = (inc%M + notInc%M)%M;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp, -1, sizeof dp);
        return findProfitScheme(n, minProfit, group, profit, 0, 0, 0);
        return 0;
    }
};