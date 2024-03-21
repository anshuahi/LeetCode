#define pii pair<int, int>
#define pb push_back
class Solution {
public:

    pii countDistinct(vector<string> &a, vector<string> &b){
        int count = 0, i =0, j =0;
        while(i < a.size() && j < b.size()){
            if(a[i] < b[j]){
                i++;
            }
            else if(a[i] > b[j]){
                j++;
            }
            else {
                i++, j++;
                count++;
            }
        }
        return {a.size() - count, b.size()-count};
    }

    long long distinctNames(vector<string>& ideas) {
        vector<vector<string>> v(26);
        map<string, bool> mp;
        for(auto s: ideas){
            mp[s] = true;
            v[s[0]-'a'].pb(s.substr(1));
        }

        for(auto &x: v){
            sort(x.begin(), x.end());
        }
        long long int ans = 0;
        for(int i = 0; i < 26; i++){
            for(int j = i+1; j < 26; j++){
                pii p = countDistinct(v[i], v[j]);
                ans += 1LL* p.first * p.second*2;
            }
        }

        return ans;
    }
};