class Solution {
public:
    
    string ans(string a, string b) {
        int m = a.length();
        int n = b.length();
        string s = "";
        int carry = 0, i;
        for(i = 0; i < n; i++){
            int x = a[i]-'0';
            int y = b[i] - '0';
            int z = x + y + carry;
            carry = z/2;;
            s += (z%2) + '0';
        }
        
        while(i < m) {
            int x = a[i]-'0';
            int z = x + carry;
            carry = z/2;;
            s += (z%2) + '0';
            i++;
        }
        
        if(carry == 1){
            s += '1';
        }
        
        reverse(s.begin(), s.end());
        
        return s;
    }
    
    
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        if(a.length() > b.length()){
            return ans(a, b);
        }
        return ans(b, a);
    }
};