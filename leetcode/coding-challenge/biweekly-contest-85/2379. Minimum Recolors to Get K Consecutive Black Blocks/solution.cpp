class Solution {
public:
    int minimumRecolors(string v, int k) {
        int n = v.size();
        
        int ans = k;
        int i = 0;
        int curr = 0;
        for(; i < k; i++){
            if(v[i] == 'B'){
                curr++;
            }
        }
        
        ans = min(ans, k-curr);
        
        for(; i < n; i++){
            if(v[i] == 'B'){
                curr++;
            }
            if(v[i-k] == 'B'){
                curr--;
            }
            
            ans = min(ans, k-curr);
        }
        
        return ans;
    }
};