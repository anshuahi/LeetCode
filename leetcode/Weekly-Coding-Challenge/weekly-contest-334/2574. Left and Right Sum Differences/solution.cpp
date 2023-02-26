#define pb push_back
class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& v) {
        vector<int> l, r, ans;
        l.pb(0);
        r.pb(0);
        int n =v.size();
        for(int i = 0; i < n-1; i++){
            l.pb(v[i]+l.back());
            r.pb(v[n-i-1]+r.back());
        }
        reverse(r.begin(), r.end());
        for(int i = 0; i < n; i++){
            ans.pb(abs(l[i]-r[i]));
        }
        
        return ans;
    }
};