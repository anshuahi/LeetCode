/*

https://leetcode.com/problems/first-missing-positive/description
Approach:
    1. Swap all numbers in the range 1 to n, to their respective index
    2. check the first number which is not at their index, nums[idx] != idx+1

*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int checkNum = 1;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int j = i;
            // Swapping all numbers in the range 1 to n, to their respective index
            while(1 <= nums[j] && nums[j] <= n &&nums[j] != nums[nums[j]-1]){
                swap(nums[j], nums[nums[j]-1]);
            }
        }

        for(int i = 0; i < n; i++){
            if(nums[i] != i+1){
                return i+1;
            }
        }

        return n+1;
    }
};