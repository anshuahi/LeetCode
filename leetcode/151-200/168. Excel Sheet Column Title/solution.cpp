class Solution {
public:
    string convertToTitle(int n) {
        
        string s;
        while(n > 0){
            n --;
            int x = n%26;
            char c = ('A' + x);
            s += c;
            n = n/26;
        }
        
        reverse(s.begin(), s.end());
        
        return s;
    }
};