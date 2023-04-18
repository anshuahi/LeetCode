class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& v) {
        int ans = 0, ind = 0;
        int n = v.size();
        
        for(int i = 0; i < n; i++){
            int s = 0;
            for(auto x: v[i]){
                s += x;
            }
            if(s > ans){
                ind = i;
                ans = s;
            }
        }
        
        return {ind, ans};
    }
};