class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        string p = "";
        for(int i = 0; i < s.length(); i++){
            if(('a' <= s[i] && s[i] <= 'z') || ('0' <= s[i] && s[i] <= '9')){
                p += s[i];
            }
        }
        
        s = p;
        reverse(s.begin(), s.end());
        
        return s == p;
        
    }
};