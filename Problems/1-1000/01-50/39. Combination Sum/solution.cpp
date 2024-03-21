#define pb push_back
class Solution {
public:
    
    vector<vector<int>> ans;
    
    void sumComb(vector<int> &v, int ind, int t, vector<int> sum) {
        if(ind >= v.size() || t < 0){
            return;
        }
        
        if(t == 0){
            ans.pb(sum);
            return;
        }
        sumComb(v, ind+1, t, sum);      //  leave the current element
        sum.pb(v[ind]);
        sumComb(v, ind, t-v[ind], sum); //  add the current element and call recursive
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        sumComb(candidates, 0, target, v);
        
        return ans;
    }
};