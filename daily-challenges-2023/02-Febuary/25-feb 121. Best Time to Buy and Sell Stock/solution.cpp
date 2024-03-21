class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        if(n == 1)
            return 0;
        int a = p[0];
        int b = 0;
        int ans = 0;
        for(int i = 1; i < n; i++){
            if(a < p[i]){
                ans = max(ans, p[i] - a);
            }
            else {
                a = p[i];
            }
        }
        
        return ans;
    }
};