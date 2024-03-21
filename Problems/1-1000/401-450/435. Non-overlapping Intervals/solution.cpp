#define pb push_back

class Solution {
public:
    
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        if(v.size() <= 1)
            return 0;
        // int n = v.size();
        sort(v.begin(), v.end());
        int ans = 0;
        int e = v[0][1];
        for(int i = 1; i < v.size(); i++){
            if(e > v[i][0]){
                ans++;
                e = min(e, v[i][1]);
            }
            else{
                e = v[i][1];
            }
        }
        
        return ans;
    }
};
