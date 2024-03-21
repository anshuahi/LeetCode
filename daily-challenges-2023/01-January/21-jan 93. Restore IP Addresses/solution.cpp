#define pb push_back
class Solution {
public:
    vector<string> v;

    bool isZero(string s){
        for(auto x: s){
            if(x != '0')
                return false;
        }
        return true;
    }

    bool isValid(string s){
        if(isZero(s)){
            if(s.size() == 1)
                return true;
            return false;
        }
        if(s[0] == '0'){
            return false;
        }
        int x = stoi(s);
        return x <= 255;
    }

    string convert(vector<string> &st){
        return st[0] + "." + st[1] + "." + st[2] + "." + st[3];
    }

    void dfs(int i, string &s, vector<string> &tillNow, string curr){
        if(tillNow.size() > 4 || i > s.size()){
            return;
        }
        if(i == s.size() && tillNow.size() == 4){
            string x = convert(tillNow);
            v.pb(x);
            return;
        }
        if(i == s.size() || tillNow.size() == 4){
            return;
        }
        curr += s[i];
        if(isValid(curr)){
            tillNow.pb(curr);
            dfs(i+1, s, tillNow, "");
            tillNow.pop_back();
            dfs(i+1, s, tillNow, curr);
        }
        return;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> tillNow;
        dfs(0, s, tillNow, "");
        vector<string> ans;
        for(auto x: v){
            ans.pb(x);
        }
        return v;
    }
};