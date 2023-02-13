#define pb push_back
class Solution {
public:
    string toBinary(int &n){
        if(n == 0){
            return "0";
        }
        string s = "";
        while(n > 0){
            s += (n%2 + '0');
            n /= 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> ans;
        int f;
        int l, r;
        int val = 0;
        string p;
        l = 0;
        while(l < s.size() && s[l] == '0'){
            l++;
        }
        for(auto x: queries){
            f = x[0] ^ x[1];
            if(f == 0 && s[0] == '0'){
                ans.pb({0, 0});
                continue;
            }
            p = toBinary(f);
            bool b = false;
            for(int i = max(0, l-1); i < s.size()-p.size()+1; i++){
                if(s.substr(i, p.size()) == p){
                    r = i+p.size()-1;
                    ans.pb({i, r});
                    b = true;
                    break;
                }
            }
            if(!b){
                ans.pb({-1, -1});
            }
        }
        return ans;
    }
};