class Solution {
public:
    int titleToNumber(string s) {
        
        int ans = 0;
        int n = s.length();
        
        for(int i = 0; i < n; i++) {
            int x = (s[i] - 'A');
            x++;
            
            ans = ans*26 + x;
        }
        
        return ans;
    }
};