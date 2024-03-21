class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == val){       // replacing val with 1000
                nums[i] = 1000;
            }
        }
        //  sorting the array so only distinct elements comes before 1000s
        sort(nums.begin(), nums.end());     
        
        for(int p = 0; p < nums.size(); p++){
            if(nums[p] != 1000)
                count++;
        }
        return count;
    }
};