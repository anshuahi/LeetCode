class Solution {
public:
    string mergeAlternately(string a, string b) {
        int i = 0, j = 0;
        string s = "";
        while(i < a.size() && j < b.size()){
            s += a[i++];
            s += b[j++];
        }
        
        while(i < a.size()){
            s += a[i++];
        }
        while(j < b.size()){
            s += b[j++];
        }
        return s;
    }
};