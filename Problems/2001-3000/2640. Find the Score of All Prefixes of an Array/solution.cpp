#define ll long long
#define pb push_back

class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& a) {
        vector<long long> v;
        int n = a.size();
        int mx = a[0];
        v.pb(mx*2);
        ll sum = mx*2;
        for(int i = 1; i < n; i++){
            mx = max(mx, a[i]);
            sum += a[i] + mx;
            v.pb(sum);
        }
        return v;
    }
};