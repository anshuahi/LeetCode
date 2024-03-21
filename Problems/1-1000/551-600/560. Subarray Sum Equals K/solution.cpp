class Solution {
public:
    int subarraySum(vector<int>& v, int k) {
        int sum = 0;
        int ind = 0, ans = 0;
        map<int, int> mp;
        mp[0] = 1;
        
        for(int i= 0; i < v.size(); i++){
            sum += v[i];
            if(mp[sum-k] != 0){
                ans += mp[sum-k];
            }
            if(mp[sum] == 0){
                mp[sum] = 1;
            }
            else {
                mp[sum]++;
            }
            
        }
        
        return ans;
    }
};