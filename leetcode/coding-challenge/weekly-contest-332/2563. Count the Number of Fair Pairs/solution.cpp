#define ll long long 
class Solution {
public:
    long long countFairPairs(vector<int>& v, int lower, int upper) {
        int n = v.size();
        ll ans = 0;
        sort(v.begin(), v.end());
        for(int i = 0; i < n-1; i++){
            auto lo = lower_bound(v.begin()+i+1, v.end(), lower-v[i]);
            auto up = upper_bound(v.begin()+i+1, v.end(), upper-v[i]);
            ans += (up-lo);
        }
        
        return ans;
    }
};