class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        auto l = lower_bound(nums.begin(), nums.end(), target);
        auto r = upper_bound(nums.begin(), nums.end(), target);
        int p = l - nums.begin(), q = r - nums.begin();
        vector<int> ans;
        while(p < q){
            ans.push_back(p++);
        }

        return ans;
    }
};