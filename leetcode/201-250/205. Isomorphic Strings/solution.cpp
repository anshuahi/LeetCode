class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if(s.length() != t.length())
            return false;
        
        map<char, char> m1, m2;
        
        for(int i = 0; i < s.length(); i++){
            if(m1[s[i]] == '\0' && m2[t[i]] == '\0'){
                m1[s[i]] = t[i];
                m2[t[i]] = s[i];
            }
            else if(m1[s[i]] != '\0' && m2[t[i]] != '\0') {
                if(m1[s[i]] != t[i] || m2[t[i]] != s[i])
                    return false;
            }
            else {
                return false;
            }
        }
        
        
        return true;
    }
};