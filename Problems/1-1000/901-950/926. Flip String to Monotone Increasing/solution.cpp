class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int ones = 0;
        int zeros = 0;
        for(auto x: s) {
            if(x == '1'){
                ones++;
            }
            else {
                zeros++;
            }
        }
        // convert all zeros to one and vice versa
        int ans = min(zeros, ones);
        int startOnes = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                startOnes++;
            }
            else {
                zeros--;
            }
            // check at each index if we convert all left side ones to zero and right side zeros to one
            ans = min(ans, startOnes + zeros);
        }

        return ans;
    }
};