class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        if(n  == 1){
            return {{nums[0]}};
        }
        vector<vector<int>> v, q;
        vector<int> p;
        for(int i = 0; i < n; i++) {
            p.clear();
            for(int j = 0; j < n; j++) {
                if(i != j) {
                    p.push_back(nums[j]);
                }
            }
            v = permute(p);         // call recursive
            for(int j = 0; j < v.size(); j++) {
                v[j].push_back(nums[i]);
                q.push_back(v[j]);
            }
        }
        
        return q;
    }
};