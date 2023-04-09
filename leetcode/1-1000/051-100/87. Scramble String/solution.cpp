#define pss pair<string, string>
class Solution {
public:
    map<pss, int> mp;

    int scramble(string s1, string s2){
        int n = s1.size();
        string a = s1, b = s2;
        if(mp[{a, b}] != 0){
            return mp[{a, b}];
        }
        // cout << s1 << " \n" << s2 << endl;
        if(n <= 2){
            return true;
        }

        // bool b = false;
        vector<int> p(26), q(26), r(26);
        for(int i = 0; i < n-1; i++){
            p[a[i]-'a']++;
            q[b[i]-'a']++;
            r[b[n-i-1]-'a']++;
            if(p == q){
                if(isScramble(a.substr(0, i+1), b.substr(0, i+1)) && 
                    isScramble(a.substr(i+1), b.substr(i+1)) ){
                    mp[{a, b}] = 1;
                    return true;
                }
            }
            if(p == r){
                if(isScramble(a.substr(0, i+1), b.substr(n-i-1)) && 
                    isScramble(a.substr(i+1), b.substr(0, n-i-1)) ){
                    mp[{a, b}] = 1;
                    return true;
                }
            }
        }
        mp[{a, b}] = -1;
        return false;
    }

    bool isScramble(string s1, string s2) {
        int n = s1.size();
        // cout << s1 << " \n" << s2 << endl;
        string a = s1, b = s2;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        if(s1 != s2){
            return false;
        }
        if(n <= 2){
            return true;
        }
        return scramble(a, b) == 1;

        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    }
};