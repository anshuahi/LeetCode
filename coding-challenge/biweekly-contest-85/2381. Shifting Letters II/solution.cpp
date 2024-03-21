class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> v(n+1, 0);
        for(auto x: shifts){
            if(x[2]){
                v[x[0]]++;
                v[x[1]+1]--;
            }
            else{
                v[x[0]]--;
                v[x[1]+1]++;
            }
        }
        string p = "";
        int c = 0;
        for(int i = 0; i < n; i++){
            c = (c+v[i])%26;
            p += 'a' + ((s[i]-'a') + c%26+26)%26;
        }
        
        return p;
    }
};