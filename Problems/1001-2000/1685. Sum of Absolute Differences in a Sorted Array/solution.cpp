#define pb push_back
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& v) {
        vector<int> ans;
        vector<int> sum;
        int n = v.size();
        sum.pb(v[0]);
        int total = v[0];
        for(int i = 1; i < n; i++){
            sum.pb(v[i]+sum.back());
            total += v[i];
        }
        int x = 0;
        for(int i = 0; i < n; i++){
            x = ((i+1)*v[i] - sum[i]) + total-sum[i]-(n-i-1)*v[i];
            ans.pb(x);
        }

        return ans;
    }
};