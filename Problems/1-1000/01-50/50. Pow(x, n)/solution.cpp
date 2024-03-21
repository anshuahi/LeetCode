class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0 || x == 1)
            return x;
        if(n == 0)
            return 1;
        if(n == 1)
            return x;
        if(n == -1)
            return 1.0/x;
        if(n < 0){
            return (1.0/x)*myPow(1.0/x, -(n+1));
        }
        double p = myPow(x,n/2);
        if(n%2 == 1){
            return x * p*p;
        }
        return p*p;
    }
};