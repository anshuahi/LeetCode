class Solution {
public:
    
    vector<string> split(string s){
        vector<string> v;
        string x = "";
        for(auto s1: s){
            if(s1 == ' '){
                v.push_back(x);
                x = "";
            }
            else {
                x += s1;
            }
        }
        
        if(x != "")
            v.push_back(x);
        
        return v;
    }
    
    bool wordPattern(string p, string s) {
        vector<string> v = split(s);
        if(v.size() != p.length())
            return false;
        
        map<char, string> m1;
        map<string, char> m2;
        
        for(int i = 0; i < v.size(); i++){
            if(m1[p[i]] == "" && m2[v[i]] == '\0'){
                m1[p[i]] = v[i];
                m2[v[i]] = p[i];
            }
            else if(m1[p[i]] != "" && m2[v[i]] != '\0'){
                if(m1[p[i]] != v[i] || m2[v[i]] != p[i])
                    return false;
            }
            else {
                return false;
            }
        }
        return true;
    }
};