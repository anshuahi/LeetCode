class Solution {
public:
    unordered_map<string, int>m, m1;
    bool check(string s, int len){
        m1 = m;
        for(int i = 0; i <= s.size()-len; i += len){
            string tmp = s.substr(i, len);
            if(m1.find(tmp) == m1.end())
                return false;
            m1[tmp]--;
            if(m1[tmp] == 0)
                m1.erase(tmp);
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        for(int i = 0; i < words.size(); i++)
            m[words[i]]++;
        
        int len = words.size()*words[0].size();
        if(s.size() < len)return ans;
        for(int i = 0; i <= s.size()-len; i++){
            string tmp = s.substr(i, len);
            if(check(tmp, words[0].size()))ans.push_back(i);
        }
        return ans;
    }
};