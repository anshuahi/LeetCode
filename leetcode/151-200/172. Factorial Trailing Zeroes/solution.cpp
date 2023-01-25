class Solution {
public:
    int trailingZeroes(int n) {
        int c = 0;
        int p = 5;
        while(p <= n){
            c += n/p;
            p *= 5;
        }

        return c;
    }
};