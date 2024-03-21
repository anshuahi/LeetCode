// bool comp()

class Solution {
public:
    
    map<char, int> mp;
    
    bool comp(string a, string b){
        int i = 0, j = 0;
        while(i < a.size() && j < b.size()){
            if(mp[a[i]] < mp[b[j]]){
                return true;
            }
            if(mp[a[i]] > mp[b[j]]){
                return false;
            }
            i++;j++;
        }
        
        if(i == a.size())
            return true;
        return false;
    }
    
    bool isAlienSorted(vector<string>& w, string order) {
        for(int i = 0; i < order.size();i++){
            mp[order[i]] = i;
        }

        for(int i = 1; i < w.size();i++){
            if(!comp(w[i-1], w[i])){
                return false;
            }
        }

        return true;
        
    }
};