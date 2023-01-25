class Solution {
public:
    
    void make(string s, int a, int b, vector<string> &v){
        
        if(a < 0 || b < 0){
            return;
        }
        if(a == 0 && b == 0){
            v.push_back(s);
            return;
        }
        
        make(s + "(", a-1, b, v);
        if(b > a){
            make(s + ")", a, b-1, v);
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        make("", n,n, v);
        
        return v;
    }
};