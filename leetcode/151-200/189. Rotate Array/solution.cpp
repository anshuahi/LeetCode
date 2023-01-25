class Solution {
public:
    void rotate(vector<int>& v, int k) {
        int n = v.size();
        k = k%n;
        if(k == 0)
            return ;
        
        vector<int> a = v;
        int g = gcd(k, n);
        for(int i = 0; i < g; i++){
            int t = v[i];
            int j = i;
            while(true) {
                int d = (j + n - k)%n;
                if(d == i){
                    break;
                }
                v[j] = v[d];
                j = d;
            }
            v[j] = t;
        }
        return;
    }
};