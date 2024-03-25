/*
Question: https://leetcode.com/problems/find-all-duplicates-in-an-array/

Approach: 
    1. iterate the array, for each element num in nums,
    2. mark the occurrences by negating the value at the idx-th index: nums[abs(num)-1] *= -1;
        if value is already negative, means the duplicate element, else mark it negative.
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int num = abs(nums[i]);
            int idx = num-1;
            if(nums[idx] < 0){
                res.push_back(num);
            }

            nums[idx] *= -1;
        }

        return res;
    }
};