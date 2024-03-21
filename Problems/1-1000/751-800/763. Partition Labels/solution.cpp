#define pb push_back

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> v;
        vector<bool> vis(26, false);
        
        vector<int> last(26, -1);
        for(int i = 0; i < s.size();i++){
            last[s[i]-'a'] = i;
        }
        
        int i = 0;
        int n = s.size();
        if(n == 1)
            return {1};
        while(i < s.size()){
            char c = s[i];
            int en = -1;
            vis[(c-'a')] = true;
            for(int j = n-1; j > i; j--){
                if(s[j] == c){
                    en = j;
                    break;
                }
            }
            if(en == -1){
                v.pb(1);
                i++;
            }
            else {
                for(int p = i+1; p < en; p++){
                    char c = s[p];
                    if(vis[(c-'a')])
                        continue;
                    vis[(c-'a')] = true;
                    en = max(last[(c-'a')], en);
                }
                v.pb(en - i+1);
                i = en+1;
            }
        }
        
        return v;
        
    }
};