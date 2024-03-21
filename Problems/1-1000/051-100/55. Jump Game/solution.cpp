class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int p = 0;
        
        for(int i = 0; i < n; i++){
            if(i <= p)
                p = max(p, i + nums[i]);
        }
        
        return p >= n-1;
    }
};