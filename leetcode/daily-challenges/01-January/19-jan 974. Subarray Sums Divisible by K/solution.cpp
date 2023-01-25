class Solution {
public:
    int subarraysDivByK(vector<int>& v, int k) {
        int n = v.size();
        vector<int> dp(k, 0);
        dp[0] = 1;

        int ans = 0;
        int res = 0, x;
        for(int i = 0; i < n; i++){
            res += (v[i]%k+k)%k;
            res %= k;
            dp[res%k] ++;
        }

        for(auto x: dp){
            ans += (x*(x-1))/2;
        }

        return ans;
    }
};