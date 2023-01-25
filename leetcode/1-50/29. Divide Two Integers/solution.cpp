class Solution {
public:
    int divide(int dividend, int divisor) {
        long a = dividend;
        a /= divisor;
        long x = pow(2, 31);
        // cout << a << " " << x << endl;
        if(a < -x){
            return -x;
        }
        if(a > x - 1){
            return x-1;
        }
        return a;
    }
};