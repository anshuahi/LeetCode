class Solution {
public:
    
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        
        string s = "11";
        string p;
        for(int i = 3; i <= n; i++){
            p = "";
            int count = 1;
            s += "$";
            for(int i = 1; i < s.size(); i++){
                if(s[i] == s[i-1]){
                    count++;
                }
                else {
                    p += to_string(count) + s[i-1];
                    count = 1;
                }
                
            }

            s = p;
        }
        
        return s;
    }
};