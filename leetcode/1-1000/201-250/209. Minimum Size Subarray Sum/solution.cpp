class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int sum = 0;
        for(int i = 0; i < n; i ++){
            sum += nums[i];
            if(target <= nums[i])
                return 1;
        }
        
        if(sum < target){
            return 0;
        }
        
        // target = sum -target;
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            target -= nums[i];
            
            while(target <= 0 && l < i){
                ans = min(ans, i-l + 1);
                target += nums[l++];
            }
            
        }
        return ans == INT_MAX? 0 : ans;
    }
};