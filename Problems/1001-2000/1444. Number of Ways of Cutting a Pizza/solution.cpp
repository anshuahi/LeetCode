#define ll long long
#define M 1000000007
class Solution {
public:

    bool isValid(vector<string>& pizza, int sr, int sc, int er, int ec, int cut){
        int apple = 0;
        for(int i = sr; i < er; i++){
            for(int j = sc; j < ec; j++){
                if(pizza[i][j] == 'A'){
                    return true;
                }
            }
        }
        return false;
    }

    int solve(vector<string>& pizza, vector<vector<vector<int>>> &dp, int sr, int sc, int cut){
        if(cut == 0){
            return dp[sr][sc][cut] = 1;
        }
        if(sr == pizza.size() || sc == pizza[0].size()){
            return dp[sr][sc][cut] = 0;
        }
        if(dp[sr][sc][cut] != -1){
            return dp[sr][sc][cut];
        }
        int n = pizza.size(), m = pizza[0].size();
        ll ans = 0;
        // horizontal cut
        for(int i = sr; i < pizza.size()-1; i++){
            bool upperCut = isValid(pizza, sr, sc, i+1, pizza[0].size(), 0);
            bool lowerCut = isValid(pizza, i+1, sc, pizza.size(), pizza[0].size(), cut-1);
            if(upperCut && lowerCut){
                ans += solve(pizza, dp, i+1, sc, cut-1);
                ans %= M;
            }
        }
        
        // vertical cut
        for(int i = sc; i < pizza[0].size()-1; i++){
            bool upperCut = isValid(pizza, sr, sc, pizza.size(), i+1, 0);
            bool lowerCut = isValid(pizza, sr, i+1, pizza.size(), pizza[0].size(), cut-1);
            if(upperCut && lowerCut){
                ans += solve(pizza, dp, sr, i+1, cut-1);
                ans %= M;
            }
        }

        return dp[sr][sc][cut] = ans;
    }

    int ways(vector<string>& pizza, int k) {
        int n = pizza.size();
        int m = pizza[0].size();
        if(n == 0){
            return 0;
        }
        int apple = 0;
        for(auto p: pizza){
            for(auto x: p){
                if(x == 'A'){
                    apple++;
                }
            }
        }
        if(apple < k){
            return 0;
        }
        vector dp(n+1, vector(m+1, vector(k+1, -1)));
        return solve(pizza, dp, 0, 0, k-1);
    }
};