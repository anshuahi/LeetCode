class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i = 1; i <= n/2; i++){
            if(s.substr(0, n-i) == s.substr(i) && n%i == 0){
                // cout << i << endl;
                return true;
            }
        }
        return false;
    }
};
// #genius