class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n = s.length();
        string r = s;
        
        int ans = 0;
        bool b = true;
        while(b){
            b = false;
            for(int i = 0; i < n-1; i++){
                if(s[i] == '0' && s[i+1] == '1'){
                    s[i] = '1';
                    s[i+1] = '0';
                    i++;
                    b = true;
                }
            }
            ans ++;
        }
        
        
        return ans-1;
    }
};