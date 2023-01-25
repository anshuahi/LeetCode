class Solution {
public:

    string upper(string w){
        string s = "";
        for(auto x: w){
            s += toupper(x);
        }

        return s;
    }

    bool detectCapitalUse(string w) {

        string b = upper(w);
        if(b == w)
            return true;

        for(int i = 1; i < w.size(); i++){
            if(tolower(w[i]) != w[i])
                return false;
        }

        return true;
    }
};