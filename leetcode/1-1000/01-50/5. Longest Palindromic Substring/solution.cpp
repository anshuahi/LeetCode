class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int count = 0;
        int p = 0;
        int ind = 0;
        for(int i = 0; i < n; i++) {
            // odd length palindrome
            p = 1;
            int st = i-1, e = i+1;
            while(st >= 0 && e < n && s[st] == s[e]) {
                st--;
                e++;
                p+=2;
            }
            
            if(p > count){
                ind = st+1;     // store the index of longest palindrome
                count = p;
            }

            // even length palindrome
            st = i, e = i+1;
            p = 0;
            while(st >= 0 && e < n && s[st] == s[e]) {
                p += 2;
                if(p > count) {
                    count = p;
                    ind = st;   // store the index of longest palindrome
                }
                st--;
                e++;
                
            }
            
        }
        
        return s.substr(ind, count);
    }
};