#define pii pair<int, int>
#define pb push_back
class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> ans;
        long long num;
        int f;
        int n = s.size();
        unordered_map<int, pii> mp;
        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                if(!mp.count(0)){
                    mp[0] = {i, i};
                }
                continue;
            }
            num = 0;
            for(int j = i; j <= min(i+32, n-1); j++){
                num = (num << 1) + (s[j] - '0');
                if(!mp.count(num)) mp[num] = make_pair(i,j);
                else {
                    if(mp[num].second - mp[num].first > j - i){
                        mp[num] = make_pair(i,j);
                    }
                }
            }
        }
        
        for(auto x: queries){
            f = x[0] ^ x[1];
            if(mp.count(f)){
                ans.pb({mp[f].first, mp[f].second});
            }
            else {
                ans.pb({-1, -1});
            }
        }
        return ans;
    }
};