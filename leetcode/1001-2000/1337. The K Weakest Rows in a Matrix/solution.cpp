#define pii pair<int, int>
#define pb push_back
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pii> v;
        int num;
        int i = 0;
        for(auto row: mat){
            num = 0;
            for(int soldier: row){
                num += soldier;
            }
            v.pb({num, i++});
        }

        sort(v.begin(), v.end());
        vector<int> ans;
        i = 0;
        while(i < k && i < v.size()){
            ans.pb(v[i].second);
            i++;
        }

        return ans;
    }
};