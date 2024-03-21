#define pb push_back
#define ll long long int
class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        unordered_map<int, int> mp, m1, m2;
        int mn=INT_MAX;
        for(auto x: b1){
            mp[x]++;
            m1[x]++;
            mn = min(mn, x);
        }
        for(auto x: b2){
            mp[x]++;
            m2[x]++;
            mn = min(mn, x);
        }
        
        for(auto x: mp){
            if(x.second%2 == 1){
                return -1;
            }
        }
        ll ans = 0, ans1 = 0, a1;
        int p, i;
       
        vector<int> u, v;
        for(auto x: m1){
            p = mp[x.first]/2;
            i=x.second;
            while(i > p){
                u.pb(x.first);
                i--;
            }
        }
        for(auto x: m2){
            p = mp[x.first]/2;
            i=x.second;
            while(i > p){
                v.pb(x.first);
                i--;
            }
        }
        sort(v.begin(), v.end());
        sort(u.begin(), u.end());
        ans = 0;
        int n = v.size();
        for(int i = 0; i < n; i++){
            ans += min(min(v[i], u[n-i-1]), 2*mn);
        }
        
        return ans;
    }
};