class Solution {
public:
    void rotate(vector<vector<int>>& v) {
        int n = v.size();
        if(n == 1)
            return;
        int x = n/2;
        for(int k = 0; k < x; k++){
            int st = k, en = n-k-1;
            for(int i = st; i < en; i++){
                int p = i - st;
                int t = v[k][i];
                v[k][i] = v[en-p][k];
                v[en-p][k] = v[en][en-p];
                v[en][en-p] = v[p+st][en];
                v[p+st][en] = t;
            }
        }
    }
};