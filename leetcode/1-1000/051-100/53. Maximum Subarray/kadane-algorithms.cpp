class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int m = nums[0];
        int sum = 0;
        // this algo is known as kadane algorithm
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum > m){
                m = sum;
            }
            if(sum < 0){
                sum = 0;
            }
        }
        return m;
    }
};