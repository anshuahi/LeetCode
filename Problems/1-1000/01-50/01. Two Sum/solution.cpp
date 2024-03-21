class Solution {
public:
    
    
    vector<int> twoSum(vector<int>& v, int target) {
        int n = v.size();
        
        // iterate through all the possible pairs
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(v[i] + v[j] == target){
                    return {i, j};
                }
            }
        }

        return {-1, -1};
    }
};