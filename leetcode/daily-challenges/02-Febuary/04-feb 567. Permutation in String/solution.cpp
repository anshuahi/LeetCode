class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }
        vector<int> f1(26, 0), f2(26, 0);
        for(auto x: s1){
            f1[x-'a']++;
        }
        // check for every window of length n
        int n = s1.size();
        for(int i = 0; i < n; i++){
            f2[s2[i]-'a']++;
        }
        if(f1 == f2){
            return true;
        }
        for(int i = n; i < s2.size(); i++){
            
            f2[s2[i]-'a']++;
            f2[s2[i-n]-'a']--;
            if(f1 == f2){
                return true;
            }
        }
        return false;
    }
};