class Solution {
public:
    int majorityElement(vector<int>& v) {
        sort(v.begin(), v.end());
        
        int mid = v.size()/2;
        
        return v[mid];
        
    }
};