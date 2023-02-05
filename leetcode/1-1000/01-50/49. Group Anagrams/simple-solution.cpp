#define pii pair<string, int>
#define mp make_pair
#define pb push_back

bool comp(pii a, pii b){
    return a.first < b.first;
}

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {

        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        
        int n = s.size();
        string p;
        for(int i = 0; i < n; i++){
            p = s[i];
            sort(p.begin(), p.end());
            mp[p].pb(s[i]);
        }

        for(auto x: mp){
            ans.pb(x.second);
        }
        
        return ans;
    }
};
