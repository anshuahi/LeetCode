class Solution {
public:
    int countPrimes(int n) {
        if(n <= 1)
            return 0;
        vector<bool> v(n, true);

        v[0] = false;
        v[1] = false;
        int count = 0;
        for(int i = 2; i*i < n; i++){
            if(v[i]){
                for(int j = 2*i; j < n; j+=i){
                    v[j] = false;
                }
            }
        }
        for(int i = 2; i < n; i++){
            if(v[i])
                count++;
        }

        return count;
    }
};