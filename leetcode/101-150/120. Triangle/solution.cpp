#define pb push_back

class Solution {
public:
    int minimumTotal(vector<vector<int>>& v) {
        int n = v.size();
        if(n == 1){
            return v[0][0];
        }
        if(n == 2){
            
        }
        int currN = 1;
        vector<int> v1, v2;
        v1.pb(v[0][0]);
        
        for(int i = 1; i < n; i++){
            v2.clear();
            for(int j = 0; j < v[i].size(); j++){
                if(j == 0){
                    v2.pb(v[i][j] + v1[0]);
                } else if(j == v[i].size()-1){
                    v2.pb(v[i][j] + v1[v1.size()-1]);
                }
                else {
                    int x = v[i][j] + min(v1[j-1], v1[j]);
                    v2.pb(x);
                }
            }
            v1 = v2;
        }
        
        int ans = INT_MAX;
        for(int i = 0; i < v1.size(); i++){
            ans = min(ans, v1[i]);
        }
        
        return ans;
    }
};