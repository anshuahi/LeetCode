class Solution {
public:
    int maxDivScore(vector<int>& v, vector<int>& d) {
        sort(d.begin(), d.end());
        int ans = 0;
        int div = d[0];
        
        for(auto x: d){
            int s = 0;
            for(auto y: v){
                if(y%x == 0){
                    s ++;
                }
            }
            
            if(s > ans){
                ans = s;
                div = x;
            }
        }
        
        return div;
    }
};