class Solution {
public:
    
    int kadaneAlgo(vector<int>& nums) {
        int n = nums.size();
        
        int sum = 0;
        int ans = INT_MIN;
        
        for(int i = 0; i < n; i++){
            sum += nums[i];
            ans = max(ans, sum);
            if(sum < 0)
                sum = 0;
        }
        
        return ans;
    }
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int x = kadaneAlgo(nums);
        int sum = 0;
        if( x < 0)
            return x;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            nums[i] = -nums[i];
        }
        // cout << x << endl;
        long p = sum + kadaneAlgo(nums);
        // cout << p << endl;
        if(p > x)
            return p;
        return x;
        // return max(x, p);
    }
};