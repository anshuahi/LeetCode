#define pb push_back
class Solution {
public:
    vector<vector<int>> ans;
    
    bool find(vector<int> sum){
        for(auto x: ans){
            if(x == sum)
                return true;
        }
        
        return false;
    }
    
    void sumComb(vector<int> &v, int ind, int t, vector<int> sum) {
        
        if(t == 0){
            if(!find(sum)){
                ans.pb(sum);
            }
            return;
        }
        if(ind >= v.size() || t < 0){
            return;
        }
        sum.pb(v[ind]);
        sumComb(v, ind+1, t-v[ind], sum);
        
        sum.pop_back();
        while(ind+1 < v.size() && v[ind] == v[ind+1]){
            ind++;
        }
        sumComb(v, ind+1, t, sum);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int sum = 0;
        for(auto c: candidates){
            sum += c;
        }
        
        if(sum < target){
            return {};
        }
        vector<int> v;
        sumComb(candidates, 0, target, v);
        
        return ans;
    }
};