class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int ec) {
        int m = 0;
        for(auto x: candies){
            m = max(m, x);
        }
        vector<bool> v;
        for(auto x: candies){
            v.push_back(x+ec >= m);
        }

        return v;
    }
};