class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& v) {
        int n = v.size();
        sort(v.begin(), v.end());
        int ans = 0;
        vector<bool> vis(n, false);
        int en = n/2;
        for(int i = 0; i < n/2; i++){
            int x = v[i]*2;
            auto up = lower_bound(v.begin()+en, v.end(), x);
            int ind = (up - v.begin());
            if(ind < n){
                vis[i] = true;
                vis[ind] = true;
                en = ind+1;
                ans += 2;
            }
        }
        return ans;
    }
};