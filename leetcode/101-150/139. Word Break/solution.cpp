class Solution {
public:

    void findSub(string s, int i, unordered_map<string, bool> &mp, bool &b){
        if(i == s.size()){
            b = true;
            return;
        }
        if(b)
            return;
        string p = "";
        int n = s.size() - i;
        for(int j = n; j > 0; j--){
            p = s.substr(i, j);
            if(mp[p]){
                findSub(s, i+j, mp, b);
            }
        }
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> mp;
        for(auto w: wordDict){
            mp[w] = true;
        }
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

        // bool b = false;
        // findSub(s, 0, mp, b);

        return dp[n];
    }
};