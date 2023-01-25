class Solution {
public:

    void findSet(vector<int>& v, int i, vector<vector<int>> &a, vector<int> &t ){
        if(i == v.size()){
            a.push_back(t);
            return;
        }
        t.push_back(v[i]);
        findSet(v, i+1, a, t);
        t.pop_back();
        findSet(v,i+1, a, t);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v;
        // v.push_back({});
        vector<int> t;
        findSet(nums, 0, v, t);

        return v;
    }
};