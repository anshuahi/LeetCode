class Solution {
public:
    bool isHappy(int n) {
        
        map<int, bool> m;
        int x;
        while(true){
            x = 0;
            while(n > 0){
                int y = n%10;
                n = n/10;
                x += y*y;
            }
            
            if(x == 1)
                return true;
            
            if(m[x])
                return false;
            m[x] = true;
            n = x;
        }
    }
};