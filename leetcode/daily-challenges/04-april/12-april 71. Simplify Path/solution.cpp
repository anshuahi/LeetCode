#define pb push_back

class Solution {
public:
    
    vector<string> split(string s){
        vector<string> v;
        string p = "";
        for(int i = 0; i < s.length(); i++){
            // bool b = false;
            if(i < s.length() && s[i] == '/') {
                if(p != ""){
                    v.pb(p);
                }
                p = "";
                continue;
            }
            
            p += s[i];
        }
        if(p != ""){
            v.pb(p);
        }
        
        return v;
    }
    string simplifyPath(string path) {
        vector<string> v;
        v = split(path);
        
        stack<string> s;
        
        for(auto x: v){
            
            if(x == "."){
                continue;
            }
            if(x == ".."){
                if(!s.empty()){
                    s.pop();
                }
            }
            else {
                s.push(x);
            }
            
        }
        v.clear();
        while(!s.empty()) {
            v.pb(s.top());
            s.pop();
        }
        
        reverse(v.begin(), v.end());
        string p = "";
        for(auto x: v){
            p += "/" + x;
        }
        if(p == "")
            return "/";
        return p;
    }
};