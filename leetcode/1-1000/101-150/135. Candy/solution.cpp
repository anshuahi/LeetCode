class Solution {
public:
    int candy(vector<int>& v) {
        int n = v.size();
        
        if(n == 1)
            return 1;
        
        vector<int> l(n, 1), r(n, 1);
        
        for(int i = 0; i < n-1; i++) {
            if(v[i] < v[i+1]){
                l[i+1] = l[i]+1;
            }
        }
        
        
        for(int i = n-1; i > 0; i--) {
            if(v[i] < v[i-1]){
                r[i-1] = r[i]+1;
            }
        }
        
        int ans = 0;
        
        
        for(int i = 0; i < n; i++) {
            ans += max(l[i], r[i]);
        }
        
        
        return ans;
    }
};