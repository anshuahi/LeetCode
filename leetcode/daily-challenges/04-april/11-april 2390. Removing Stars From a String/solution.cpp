class Solution {
public:
    string removeStars(string s) {
        string p = "";
        int c = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '*'){
                c--;
            }
            else {
                if(c < p.length()){
                    p[c++] = s[i];
                }
                else {
                    p += s[i];
                    c++;
                }
            }
        }
        
        return p.substr(0, c);
    }
};