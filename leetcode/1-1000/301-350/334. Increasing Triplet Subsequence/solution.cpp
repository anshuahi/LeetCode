class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<bool> left(nums.size(), false), right(nums.size(), false);
        stack<int> s;
        
        for(int i = 0; i < nums.size(); i++){
            while(!s.empty() && nums[s.top()] < nums[i]){
                right[s.top()] = true;
                s.pop();
            }
            s.push(i);
        }
        
        while(!s.empty()){
            s.pop();
        }
        
        for(int i = nums.size()-1; i >= 0; i--){
            while(!s.empty() && nums[s.top()] > nums[i]){
                left[s.top()] = true;
                s.pop();
            }
            s.push(i);
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(left[i] && right[i])
                return true;
        }
        
        return false;
    }
};