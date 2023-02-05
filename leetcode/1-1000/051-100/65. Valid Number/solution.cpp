class Solution {
public:
    
    bool isInteger(string s){
        if(s.length() == 0)
            return false;
        int i = 0;
        if(s[0] == '-' || s[0] == '+'){
            i++;
        }
        if(i == s.size())
            return false;
        for(; i < s.size(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                continue;
            }
            else{
                return false;
            }
        }
        
        return true;
    }
    bool isPosInteger(string s){
        if(s.length() == 0)
            return false;
        int i = 0;
        for(; i < s.size(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                continue;
            }
            else{
                return false;
            }
        }
        
        return true;
    }
    bool isDecimal(string s){
        if(s.length() == 0)
            return false;
        
        
        int i = 0;
         if(s[0] == '-' || s[0] == '+'){
            i++;
        }
        
        if(i == s.size())
            return false;
        
        if(s[i] == '.' && s.size() == i+1){
            return false;   
        }
        string dec = "";
        string in = "";
        bool dot = false;
        
        for(; i < s.size(); i++){
            if(s[i] == '.'){
                if(dot)
                    return false;
                dot = true;
                continue;
            }
            if(s[i] >= '0' && s[i] <= '9'){
                continue;
            }
            return false;
        }
        // cout << dec << " " << in << endl;
        
        return true;
    }
    
    bool isNumber(string s) {
        
        int countE = 0;
        int i = 0;
        
        string dec = "";
        string in = "";
        int deci = 0;
        
        for(; i < s.size(); i++){
            
            if(s[i] == 'e' || s[i] == 'E' || s[i] == '.' || s[i] == '-' || s[i] == '+' || ('0' <= s[i] && s[i] <= '9')){
                
            }
            else {
                return false;
            }
               
            
            if(s[i] == 'e' || s[i] == 'E'){
                countE++;
                if(countE > 1)
                    return false;
                continue;
            }
            if(s[i] == '.'){
                deci++;
                if(deci > 1 || countE >= 1)
                    return false;
            }
            if(countE == 0){
                dec += s[i];
            }
            else {
                in += s[i];
            }
        }

        if(countE == 1){
            return isDecimal(dec) && isInteger(in);
        }

        return isDecimal(dec);
    }
};