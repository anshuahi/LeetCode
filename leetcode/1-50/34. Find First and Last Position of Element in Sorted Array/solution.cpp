class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int t) {
        int n = nums.size();
        if(n == 0)
            return {-1, -1};
        int x = -1, y = -1;
        bool found = false;
        // traverse the array
        for(int i = 0; i < n && nums[i] <= t; i++){
            if(nums[i] == t){
                if(!found){    // if not found update index of element to both x and y
                    found = true;    
                    x = i;
                    y = i;
                }
                else {     // if found only update index of element to y
                    y = i;
                }
            }
        }
        
        return {x, y};
    }
};
// Time complexity : O(n)
// Space complexity : O(1)

