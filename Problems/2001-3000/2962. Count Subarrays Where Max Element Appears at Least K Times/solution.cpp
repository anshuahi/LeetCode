/*
LeetCode-POTD: 2962. Count Subarrays Where Max Element Appears at Least K Times

POTD Link - https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description

Approach :     
    1. find the maximum element.
    2. increase the window size, and increase the count of max_element
    3. while the count exceeds the value K, reduce the size of the window until the count becomes less than K.
    4. add the number of all possible subarrays in ans.

*/
#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max_element = nums[0];
        for(auto num: nums){
            max_element = max(max_element, num);
        }
        long long ans = 0, count = 0;
        int l = 0, r = 0, n = nums.size();
        while(r < n){
            if(nums[r] == max_element)
                count++;
            while(count >= k && l <= r){
                if(nums[l++] == max_element)
                    count--;
                ans += (n-r);
            }
            r++;
        }

        return ans;
    }
};
