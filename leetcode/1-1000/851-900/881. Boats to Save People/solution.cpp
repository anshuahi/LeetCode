class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        int n = p.size();
        int l = 0, r = n-1;
        int ans = 0;
        sort(p.begin(), p.end());
        while(l <= r){
            int a = p[l], b = p[r];
            if(a + b <= limit){
                ans++;
                l++, r--;
            }
            else {
                ans ++;
                r--;
            }
        }

        return ans;
    }
};