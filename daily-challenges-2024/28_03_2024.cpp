/*
Question: 
    2958. Length of Longest Subarray With at Most K Frequency

POTD Link:
    https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/

Approach:
    1. increase the window size, and store count of every number
    2. if count of a number exceeds the value K, reduce the size of window until count becomes K.
    3. store the window size in ans.
*/
class Solution {
public:
    // we will use sliding window
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        int ans = 1;
        map<int, int> mp;
        while(r < n){
            mp[nums[r]]++;
            while(l < r && mp[nums[r]] > k){
                mp[nums[l++]]--;
            }

            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};
