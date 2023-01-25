class Solution {
public:

    bool backtrack(int n, vector<int> & v, vector<bool> &dp){
        if(v.size() == pow(2, n)){
            int a = v[0], b = v.back();
            int count = 0;
            for(int i = 0; i < n;i++){
                if((a & 1 << i) != (b & 1 << i)){
                    count ++;
                }
                if(count > 1){
                    return false;
                }
            }
            return true;
        }

        int a = v.back();
        int b = a;
        for(int i = 0; i < n;i++){
            b = a;
            if(a & 1 << i){
                b -= 1<<i;
            }
            else {
                b += 1 << i;
            }
            if(!dp[b]){
                v.push_back(b);
                dp[b] = true;
                if(backtrack(n, v, dp)){
                    return true;
                }
                else {
                    v.pop_back();
                    dp[b] = false;
                }
            }
        }

        return false;
    }

    vector<int> grayCode(int n) {
        int size = pow(2, n);
        vector<bool> dp(size, 0);
        vector<int> v;
        dp[0] = true;
        v.push_back(0);

        backtrack(n, v, dp);
        return v;
    }
};