class Solution {
public:
    int maxSatisfaction(vector<int>& v) {
        int ans = 0;
        int n = v.size();
        sort(v.begin(), v.end());
        int x, p;
        for(int i = 0; i < n; i++){
            x = 0;
            p = 1;
            for(int j = i; j < n; j++){
                x += p*v[j];
                p++;
            }
            ans = max(ans, x);
        }

        return ans;
    }
};