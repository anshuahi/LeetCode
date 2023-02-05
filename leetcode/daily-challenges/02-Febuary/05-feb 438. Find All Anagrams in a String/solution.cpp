class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> f1(26, 0), f2(26, 0);
        int n = s.size(), m = p.size();
        if(n < m)
            return {};
        int i, j;
        j = 0;
        for(i = 0; i < m && i < n; i++){
            f1[s[i]-'a']++;
            f2[p[i]-'a']++;
        }
        vector<int> v;
        if(f1 == f2){
            v.push_back(j);
        }
        for(; i < n; i++){
            f1[s[i]-'a']++;
            f1[s[j]-'a']--;
            j++;
            
            if(f1 == f2){
                v.push_back(j);
            }
        }

        return v;
    }
};