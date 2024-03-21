class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n, 0);
        int noZeroes = 0;
        long x = 1;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0)
                noZeroes++;
            else {
                x *= nums[i];
            }
        }
        
        if(noZeroes > 1){
            return v;
        }
        if(noZeroes == 0) {
            for(int i = 0; i < n; i++){
                v[i] = x/nums[i];
            }
            return v;
        }
        
        
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                v[i] = x;
            }
        }
        return v;
    }
};