class Solution {
public:
    int addMinimum(string s) {
        int n = s.size();
        int ans = 0;
        char prev = 'a';
        vector<int> v;
        vector<int> p = {0, 0 , 0};
        
        for(int i = 0; i < n; i++){
            if(s[i] == 'a'){
                
                if(s.substr(i+1, 2) == "bc"){
                    i+=2;
                    continue;
                }
                if(i == n-1){
                    ans += 2;
                    continue;
                }
                if(i+1 < n && s[i+1] == 'a'){
                    ans += 2;
                    continue;
                }
                
                if(i+1 < n && s[i+1] == 'b'){
                    ans += 1;
                    i++;
                    continue;
                }
                
                if(i+1 < n && s[i+1] == 'c'){
                    ans += 1;
                    i++;
                    continue;
                }               
            }
            else if(s[i] == 'b'){
                if(i == n-1){
                    ans += 2;
                    continue;
                }
                if(i+1 < n && s[i+1] == 'c'){
                    ans += 1;
                    i++;
                    continue;
                }else {
                    ans+=2;
                }
            }
            else {
                ans += 2;
            }
        }
        
        
        return ans;
    }
};