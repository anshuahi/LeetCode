#define pb push_back
class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> ans;
        int f;
        int l, r;
        int val = 0;
        for(auto x: queries){
            f = x[0] ^ x[1];
            l = 0, r = 0;
            val = (s[l]-'0');
            if(val == f){
                ans.pb({l,r});
                break;
            }
            for(int r = 1; r < s.size(); r++){
                val = val*2 + (s[r]-'0');
                if(val == f){
                    ans.pb({l,r});
                    break;                    
                }
                cout <<l << " " << r << "\t- " << val << endl;
                while(l < r && val > f){
                    val -= pow(2, r-l)*(s[l]-'0');
                    l++;
                }
                while(l < r && s[l] == '0'){
                    l++;
                }
                
                cout <<l << " " << r << "->\t" << val << endl;
                if(val == f){
                    ans.pb({l,r});
                    break;                    
                }
            }
            if(r == s.size()){
                ans.pb({-1, -1});
            }
            cout << endl;
        }
        return ans;
    }
};