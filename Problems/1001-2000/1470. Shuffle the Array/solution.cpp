#define pb push_back
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> v;
        for(int i = 0; i < n; i++){
            v.pb(nums[i]);
            v.pb(nums[i+n]);
        }

        return v;
    }
};