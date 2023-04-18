#define ll long long int
#define pb push_back
class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans;
        ll x = 0;
        for(auto w: word){
            int d = w-'0';
            x = x*10+d;
            x = x%m;
            if(x%m == 0){
                ans.pb(1);
            }
            else {
                ans.pb(0);
            }
            // x = 
        }
        
        return ans;
    }
};