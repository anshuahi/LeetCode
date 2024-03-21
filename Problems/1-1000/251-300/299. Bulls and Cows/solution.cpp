class Solution {
public:
    
    int find(string a, string b){
        vector<int> x(10, 0), y(10, 0);
        for(auto p: a){
            x[p-'0']++;
        }
        for(auto p: b){
            y[p-'0']++;
        }
        
        int ans = 0;
        for(int i = 0; i < 10; i ++){
            ans += min(x[i], y[i]);
        }
        
        return ans;
    }
    
    string getHint(string s, string g) {
        int a=0, b = 0;
        string x = "", y = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == g[i])
                a++;
            else {
                x+= s[i];
                y += g[i];
            }
                // b++;
        }
        
        return to_string(a)+"A"+to_string(find(x, y))+"B";
    }
};