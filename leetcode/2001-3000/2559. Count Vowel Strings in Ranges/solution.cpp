#define ll long long int
class Solution {
public:
    
    bool isVowel(char &x){
        if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u'){
            return true;
        }
        return false;
    }
    
    ll countVowel(string &s){
        if(isVowel(s[0]) && isVowel(s[s.size()-1])){
            return 1;
        }
        return 0;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<ll> sum(n);
        sum[0] = countVowel(words[0]);
        for(int i = 1; i < n; i++){
            sum[i] = sum[i-1] + countVowel(words[i]);
        }
        vector<int> v;
        for(auto q: queries){
            int l = q[0], r = q[1];
            if(l == 0){
                v.push_back(sum[r]);
            }
            else {
                v.push_back(sum[r] - sum[l-1]);                
            }
        }
        
        return v;
    }
};