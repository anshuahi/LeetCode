class Solution {
public:
    
    int kadaneProductAlgo(vector<int>& nums) {
        int n = nums.size();
        
        int sum = 1;
        int ans = INT_MIN;
        
        for(int i = 0; i < n; i++){
            sum *= nums[i];
            ans = max(ans, sum);
            if(sum == 0){
                sum = 1;
            }
        }
        
        return ans;
    }
    
    int maxProduct(vector<int>& nums) {
        int x = kadaneProductAlgo(nums);
        reverse(nums.begin(), nums.end());
        int y = kadaneProductAlgo(nums);
        return max(x, y);
    }
};