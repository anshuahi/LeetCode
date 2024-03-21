class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.length() < needle.length()){
            return -1;
        }

        string s;
        for(int i = 0; i < haystack.length()-needle.length()+1; i++){
            s = haystack.substr(i, needle.length());    // substring starting from i of needle length
            if(s == needle){
                return i;
            }
        }
        return -1;
    }
};