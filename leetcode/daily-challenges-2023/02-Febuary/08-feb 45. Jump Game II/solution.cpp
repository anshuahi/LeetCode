class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0;
        int currReach = 0;
        int ans = 0;
        
        for(int i = 0; i < n-1; i++) {
            if(i + nums[i] >= maxReach) {
                maxReach = i + nums[i];
            }
            
            if(i == currReach){
                currReach = maxReach;
                ans++;
            }
        }
        return ans;
    }
};
