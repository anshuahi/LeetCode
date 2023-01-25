#define pii pair<string, int>
#define mp make_pair
#define pb push_back

bool comp(pii a, pii b){
    return a.first < b.first;
}

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        vector<pii> v;
        vector<vector<string>> ans;
        vector<string> u;
        
        int n = s.size();
        for(int i = 0; i < n; i++){
            string p = s[i];
            sort(p.begin(), p.end());
            v.push_back(mp(p, i));
        }
        
        sort(v.begin(), v.end(), comp);
        for(int i = 0; i < n; i++){
            if(i == 0 || v[i].first == v[i-1].first){
                u.pb(s[v[i].second]);
            }
            else {
                ans.pb(u);
                u.clear();
                u.pb(s[v[i].second]);
            }
            
        }
        ans.pb(u);
        u.clear();
        return ans;
    }
};