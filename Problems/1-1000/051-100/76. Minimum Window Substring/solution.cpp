
  class Solution {
public:
    
    bool matches(string s, string t, int a, int b){
        
        if(b-a+1 < t.size()){
            return false;
        }
        
        int i = 0, j = a;
        
        while(i < t.size() && j <= b){
            if(t[i] == s[j]){
                i++;
                j++;
            }
            else {
                j++;
            }
        }
        
        if(i == t.size()){
            return true;
        }
        
        return false;
        
    }
    
    bool isCovered(vector<int> &a, vector<int> &b){
        for(int i = 0; i < 52; i++){
            if(a[i] < b[i])
                return false;
        }
        return true;
    }
    
    string minWindow(string s, string t) {
        int l = 0;
        int ans = INT_MAX;
        
        vector<int> a(52, 0), b(52, 0);
        
        for(auto c: t){
            if('A' <= c && c <= 'Z'){
                b[26 + (c-'A')]++;
            }
            else {
                b[(c-'a')]++;
            }
        }
        
        int st = 0, len = 0;
        int r;
        for(r = 0; r < s.size(); r++){
            // a[(s[r]-'a')]++;
            char c = s[r];
            if('A' <= c && c <= 'Z'){
                a[26 + (c-'A')]++;
            }
            else {
                a[(c-'a')]++;
            }
            while(l <= r && isCovered(a, b)){
                // cout << l << " " << r << endl;
                if(ans > r-l+1){
                    ans = r-l+1;
                    st = l;
                }
                c = s[l++];
                if('A' <= c && c <= 'Z'){
                    a[26 + (c-'A')]--;
                }
                else {
                    a[(c-'a')]--;
                }                
            }
        }
        
        if(ans == INT_MAX)
            return "";
        return s.substr(st, ans);
        // return ans;
    }
};      

