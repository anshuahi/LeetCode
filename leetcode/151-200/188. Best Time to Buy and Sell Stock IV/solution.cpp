class Solution {
public:
    
    int solveTab(int k, vector<int>& prices){
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));

        for(int index=n-1;index>=0;index--){
            for(int transactions=1;transactions<=2*k;transactions++){
                int maxProfit=0;
        
                if( (transactions & 1)==0){
                    int buyKaro=-prices[index]+dp[index+1][transactions-1];
                    int skipKaro=0+dp[index+1][transactions];
                    maxProfit=max(buyKaro,skipKaro);
                }
                else{
                    int sellKaro=prices[index]+dp[index+1][transactions-1];
                    int skipKaro=0+dp[index+1][transactions];
                    maxProfit=max(sellKaro,skipKaro); 
                }

                dp[index][transactions]=maxProfit;
            }
        }
        
        return dp[0][2*k];
    }
    
    int maxProfit(int k, vector<int>& prices) {
        return solveTab(k, prices);
    }
};