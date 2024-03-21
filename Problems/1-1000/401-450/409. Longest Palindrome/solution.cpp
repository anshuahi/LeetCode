class Solution {
public:
    int longestPalindrome(string s) {
        
        vector<int> v(26, 0), u(26, 0);
        
        for(auto x: s){
            char c = tolower(x);
            if(c == x){
                v[c-'a']++;                
            }
            else {
                u[x-'A']++;
            }
        }
        
        int ans = 0;
        bool b = false;
        
        for(auto a : v){
            // cout << a << " ";
            if(a%2 == 1){
                b = true;
                a--;
            }
            ans += a;
        }
        
        for(auto a : u){
            // cout << a << " ";
            if(a%2 == 1){
                b = true;
                a--;
            }
            ans += a;
        }
        
        if(b)
            ans++;
        
        return ans;
    }
};