#define pii pair<int, int>

class Solution {
public:
    
    
    vector<int> twoSum(vector<int>& v, int target) {
        
        vector<pii> u;
        
        for(int i = 0; i < v.size(); i++){
            u.push_back({v[i], i});         // saving the value corresponding to index
        }
        
        sort(u.begin(), u.end());
        int s = 0, e = v.size()-1;  // start and end index
        
        while(s < e){
            int twosum = u[s].first + u[e].first;
            if(twosum == target){        //      if the sum is equal to target return index of the original array
                return {u[s].second, u[e].second};
            }
            else if(twosum < target){
                s++;
            }
            else {
                e--;
            }
        }
        
        return {-1, -1};
    }
};
// Time complexity : O(nlog(n))
// Space complexity : O(1)