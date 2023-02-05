class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> v;
        int n = nums.size();
        if(n == 1){
            return {{nums[0]}};
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            //  if last number is equal to current num skip the permutation
            if(i == 0 || nums[i] != nums[i-1]){ 
                vector<int> x;
                for(int j = 0; j < n; j++){
                    if(i != j){
                        x.push_back(nums[j]);
                    }
                }
                vector<vector<int>> z = permuteUnique(x);
                for(auto q : z){
                    q.push_back(nums[i]);
                    v.push_back(q);
                }
            }
        }
        return v;
    }
};