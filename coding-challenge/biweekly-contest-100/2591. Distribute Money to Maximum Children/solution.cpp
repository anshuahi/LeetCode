class Solution {
public:
    int distMoney(int m, int c) {
        if(m < c){
            return -1;
        }
        if(m == c*8){
            return c;
        }
        if(m > c*8){
            return c-1;
        }
        if(m < 8 || m < c+7)
            return 0;
        m -= c;

        if(c*7 < m){
            return c-1;
        }
        
        int x = m/7;
        int rem = m%7;
        if(x == c-1 && rem == 3){
            return c-2;
        }
        
        return x;
        
    }
};