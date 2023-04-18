class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n = s.length();
        int ans = 0;
        int zero = 0, one = 0;
        for(int i = 0; i < n; i++){
            zero += (s[i] == '0');
            if(s[i] == '1' && zero){
                ans = max(ans+1, zero);
            }
        }       
        
        return ans;
    }
};