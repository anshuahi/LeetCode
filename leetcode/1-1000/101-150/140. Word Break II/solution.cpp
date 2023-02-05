class Solution {
public:
    unordered_map<string, bool> mp;
    bool wordBreak1(string s) {

        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        string p;
        for(int i = 1; i <= n; i++){
            p = "";
            for(int j = i; j > 0 && !dp[i]; j--){
                p = s[j-1] + p;
                if(mp[p] && dp[j-1]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }

    vector<string> findSubstr(string s, int i){
        if(i == s.size()){
            return {""};
        }
        int n = s.size();
        string p = "";
        vector<string> v, u;
        for(int j = i; j < n; j++){
            p += s[j];
            if(mp[p]){
                if(j == n-1){
                    // cout << p << endl;
                    u.push_back(p);
                    // return u;
                }
                else {
                    v = findSubstr(s, j+1);
                    for(auto x: v){
                        // if(x == ""){
                        //     u.push_back(p);
                        // }
                        // else 
                        u.push_back(p + " " + x);
                    }
                }
            }
        }
        return u;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto w: wordDict){
            mp[w] = true;
        }
        if(!wordBreak1(s)){
            return {};
        }
        return findSubstr(s, 0);
    }
};