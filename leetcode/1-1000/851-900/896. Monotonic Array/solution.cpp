class Solution {
public:

    bool isIncreasing(vector<int> &nums){
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i-1]){
                return false;
            }
        }

        return true;
    }
    
    bool isDecreasing(vector<int> &nums){
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]){
                return false;
            }
        }

        return true;
    }

    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2){
            return true;
        }

        if(nums[0] <= nums[n-1]){
            return isIncreasing(nums);
        }
        
        return isDecreasing(nums);
    }
};