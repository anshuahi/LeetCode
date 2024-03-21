class Solution {
public:
    int tribonacci(int n) {
        if(n <= 1){
            return n;
        }
        if(n == 2)
            return 1;
        vector<int> f(n+1, 0);
        f[1] = f[2] = 1;
        
        for(int i = 3; i <= n; i++){
            f[i] = f[i-1] + f[i-2] + f[i-3];
        }
        
        return f[n];
    }
};