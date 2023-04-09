class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> alpha(256, -1);
        int st = -1;
        int res = 0;
        for(int i = 0; i < s.length(); i++){
            int d = s[i];
            // if the last occurrence current element is after the starting point, reset the starting index
            if(alpha[d] > st){  
                st = alpha[d];
            }
            alpha[d] = i;
            res = max(res, i - st);
        }
        
        return res;
    }
};