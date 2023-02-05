class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        int n = v.size();
        if(n <= 1)
            return n;
        sort(v.begin(), v.end());
        
        int ans = 0;
        int sum = 1;
        
        for(int i = 1; i < n; i++){
            if(v[i] == v[i-1]){
                continue;
            }
            if(v[i] - v[i-1] == 1){
                sum++;
            }
            else {
                ans = max(sum, ans);
                sum = 1;
            }
        }
        ans = max(sum, ans);
        return ans;
    }
};