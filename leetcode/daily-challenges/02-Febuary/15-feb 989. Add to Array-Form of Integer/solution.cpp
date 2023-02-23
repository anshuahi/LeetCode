#define pb push_back
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& v, int k) {
        vector<int> a, ans;
        int n = v.size();
        while(k > 0 || n > 0){
            a.pb(k%10);
            k = k/10;
            n--;
        }
        reverse(v.begin(), v.end());
        int m = a.size();
        n = v.size();
        while(n < m){
            v.pb(0);
            n++;
        }
        int carry = 0, x;
        for(int i = 0; i < n; i++){
            x = v[i]+a[i]+carry;
            carry = x/10;
            ans.pb(x%10);
        }
        if(carry){
            ans.pb(1);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};