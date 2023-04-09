#define ll long long
#define pb push_back

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spl, vector<int>& ptn, long long scs) {
        int n = spl.size();
        int m = ptn.size();
        vector<int> ans;
        sort(ptn.begin(), ptn.end());
        for(auto x: spl){
            ll c = ceil(scs*1.0/x);
            if(1LL*ptn.back()*x < scs){
                ans.pb(0);
                continue;
            }
            if(1LL*ptn[0]*x >= scs){
                ans.pb(m);
                continue;
            }
            auto low = lower_bound(ptn.begin(), ptn.end(), c);
            int i = low - ptn.begin();
            // cout << x << " "<< i << ", \t";
            ans.pb(m-i);
        }

        return ans;
    }
};
