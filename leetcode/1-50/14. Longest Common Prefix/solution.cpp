class Solution {
public:
    string commonPrefix(string a, string b){
        int i = 0;
        while(i < a.length() && i < b.length() && a[i] == b[i]){
            i++;
        }
        return a.substr(0, i);
    }
    string longestCommonPrefix(vector<string>& s) {
        int n = s.size();
        if(n == 0){
            return "";
        }
        
        string p = s[0];
        for(int i = 1; i < s.size(); i++) {
            p = commonPrefix(p, s[i]);
        }
        return p;
    }
};