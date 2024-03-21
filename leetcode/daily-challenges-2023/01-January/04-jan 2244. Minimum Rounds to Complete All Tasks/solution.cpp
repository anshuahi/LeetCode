class Solution {
public:
    int minimumRounds(vector<int>& t) {
        map<int, int> mp;
        
        for(auto x: t){
            mp[x] ++;
        }

        int ans = 0, c;
        for(auto x: mp){
            c = x.second;
            if(c == 1){
                return -1;
            }
            ans += (c+2)/3;
        }

        return ans;
    }
};