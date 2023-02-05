#define pb push_back
class Solution {
public:
    set<vector<int>> ans;
    void backtrack(vector<int> &nums, int ind, vector<int> &v){
        if(ind == nums.size()){
            if(v.size() > 1){
                ans.insert(v);
            }
            return;
        }
        if(v.size() == 0 || nums[ind] >= v.back()){
            v.pb(nums[ind]);
            backtrack(nums, ind+1, v);
            v.pop_back();
            backtrack(nums, ind+1, v);
            return;
        }
        backtrack(nums, ind+1, v);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> v;
        backtrack(nums, 0, v);
        vector<vector<int>> res;
        for(auto x: ans){
            res.pb(x);
        }
        return res;
    }
};