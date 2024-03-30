/*
LeetCode-POTD: 992. Subarrays with K Different Integers

POTD Link - https://leetcode.com/problems/subarrays-with-k-different-integers/description/

GitHub Solution Link- https://github.com/anshuahi/LeetCode/blob/main/daily-challenges-2024/30_03_2024.cpp

*Approach* :     
Count of SubArrays with K Distinct Elements = Count of SubArrays with At Most K Distinct Elements - Count of SubArrays with At Most K-1 Distinct Elements
For *Count of SubArrays with At Most K Distinct Elements*
    1. find the window with the map size equal to k, add the window size to ans
    2. if map size exceeds k, reduce the window size.
    
*/

class Solution {
public:

    int subarraysWithAtMostKDistinctNumber(vector<int>& nums, int k){
        int ans = 0;
        int n = nums.size();
        
        int l = 0, r = 0;
        map<int, int> mp;
        while(r < n){
            mp[nums[r]]++;
            while(mp.size() > k && l <= r){
                if(mp[nums[l]] == 1){
                    mp.erase(nums[l]);
                }
                else 
                    mp[nums[l]]--;
                l++;
            }
            ans += (r-l+1);
            r++;
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithAtMostKDistinctNumber(nums, k)
            - subarraysWithAtMostKDistinctNumber(nums, k-1);
    }
};

