class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        nums.push_back(1000);
        int count = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]){       // replacing duplicate with 1000
                nums[i-1] = 1000;
            }
        }
        
        sort(nums.begin(), nums.end());     //  sorting the array so only distinct elements comes before 1000s
        
        for(int p = 0; p < nums.size(); p++){
            if(nums[p] != 1000)
                count++;
        }
        return count;
    }
};