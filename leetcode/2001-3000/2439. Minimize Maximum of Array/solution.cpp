#define ll long long
class Solution {
public:

    int minimizeArrayValue(vector<int>& v) {
        int ans = v[0];
        int n = v.size();
        ll sum = v[0];
        for(int i = 1; i < n; i++){
            sum += v[i];
            int x = ceil(sum*1.0 / (i+1));
            ans = max(x, ans);
        }

        return ans;
    }
};