class Solution {
public:
    int myAtoi(string s) {
        long p = pow(2, 31);
        long int m = 0;
        bool isNeg = false;
        int count = 0;
        
        int i = 0;
        while(i < s.length() && s[i] == ' '){
            i++;
        }
        
        for(; i < s.length(); i++){
            if(s[i] == '-' && m == 0){
                isNeg = true;
                count ++;
                if(count >= 2){
                    return 0;
                }
            }
            else if(s[i] == '+' && m == 0){
                isNeg = false;
                count++;
                if(count >= 2){
                    return 0;
                }
            }
            else if(s[i] >= '0' && s[i] <= '9'){
                m = m*10 + (s[i] - '0');
                if(m >= p){
                    if(isNeg){
                        return -p;
                    }
                    else {
                        return p-1;
                    }
                }
                count++;
            }
            else {
                break;
            }
            
        }
        if(isNeg){
            m = -m;
        }
        // cout << m << endl;
        if(m < -p)
            return -p;
        if(m >= p){
            return p-1;
        }
        return m;
    }
};