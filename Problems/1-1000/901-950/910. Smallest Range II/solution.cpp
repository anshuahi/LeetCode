class Solution {
public:


    int smallestRangeII(vector<int>& v, int k) {
        if(v.size() == 1){
            return 0;
        }
        int mn = INT_MAX, mx = INT_MIN;
        int a, b;
        sort(v.begin(), v.end());
        int n = v.size();
        int ans = v[n-1]-v[0];
        int h, l;
        for(int i = 0; i < n-1; i++){
            a = v[i], b = v[i+1];
            h = max(v[n-1]-k, a+k);
            l = min(v[0]+k, b-k);
            ans = min(ans, h-l);
        }
        
        return ans;
    }
};