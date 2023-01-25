class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        if(n <= 10)
            return {};

        unordered_map<string, int> mp;        
        string x = "";
        int i = 0;
        while(i < 10){
            x += s[i++];
        }
        mp[x]++;

        for(i = 10; i < n; i++){
            x = x.substr(1);
            x += s[i];
            mp[x]++;
        }
        vector<string> v;
        
        for(auto itr: mp){
            if(itr.second > 1){
                v.push_back(itr.first);
            }
            // cout <<  << " " << itr->second << endl;
        }
        return v;
    }
};