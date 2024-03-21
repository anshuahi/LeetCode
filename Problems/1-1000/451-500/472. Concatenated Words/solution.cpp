#define pb push_back

class Solution {
public:
    unordered_map<string, bool> mp;

    bool dfs(string &word, int ind, vector<bool>&vis){
        if(ind == word.size()){
            return true;
        }
        if(vis[ind]){
            return false;
        }
        vis[ind] = true;

        for(int i = word.size() - ((ind == 0)? 1 : 0); i > ind; i--){
            if(mp[word.substr(ind, i-ind)] && dfs(word, i, vis)){
                return true;
            }
        }
        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end());
        int n;
        for(auto w: words){
            mp[w] = true;
        }

        vector<string> v;
        string s;
        for(auto w: words){
            n = w.size();
            vector<bool> vis(n+1, false);
            if(dfs(w, 0, vis)){
                v.pb(w);
            }
        }
        return v;
    }
};