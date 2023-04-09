class Solution {
public:

    // reverse a positive integer
    long rev(int n){
        long m = 0;
        while(n > 0){
            m = m*10 + n%10;
            n = n/10;
        }

        return m >= pow(2, 31)? 0 : m;  // check if value exceeds int range i.e. 2^31
    }

    int reverse(int x) {
        long p = x;
        
        if(p >= pow(2, 31) || p < -pow(2, 31))
            return 0;
        if(p < 0){
            return -rev(-p);
        }
        return rev(p);
    }
};