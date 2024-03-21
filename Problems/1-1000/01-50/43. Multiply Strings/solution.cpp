class Solution {
public:
    
    string addString(string a, string b){
        int carry = 0;
        int i = 0, j = 0;
        string s = "";
        
        while(i < a.size() && j < b.size()){
            int x = carry + (a[i]-'0')+(b[j]-'0');
            int p = x%10;
            s += ('0' + p );
            carry = x/10;
            
            i++,j++;
        }
        
        while(i < a.size()){
            int x = carry + (a[i]-'0');
            
            int p = x%10;
            s += ('0' + p );
            carry = x/10;
            
            i++;
        }
        
        while(j < b.size()){
            int x = carry + (b[j]-'0');
            
            int p = x%10;
            s += ('0' + p );
            carry = x/10;
            
            j++;
        }
        while(carry){
            int y = carry%10;
            carry = carry/10;
            s += ('0' + y);
        }
        // reverse(s.begin(), s.end());
        
        return s;
    }
    
    bool zeroString(string s){
        for(auto x: s)
            if(x != '0')
                return false;
        return true;
    }
    
    string mult(string a, char c, int n){
        int x = c-'0';
        string s = "";
        while(n > 0){
            s += '0';
            n--;
        }
        
        int carry = 0;
        for(int i = a.size()-1; i >= 0; i--){
            int y = a[i]-'0';
            y = y*x + carry;
            carry = y/10;
            y = y%10;
            s += ('0' + y);
        }
        while(carry){
            int y = carry%10;
            carry = carry/10;
            s += ('0' + y);
        }
        
        
        return s;
    }
    
    string multiply(string s1, string s2) {
        
        if(zeroString(s1) || zeroString(s2))
            return "0";
        
        string s="0";
        for(int i = 0; i < s2.size(); i++){
            string x = mult(s1, s2[i], s2.size()-i-1);
            s = addString(x, s);
        }
        reverse(s.begin(), s.end());
        return s;
    }
};