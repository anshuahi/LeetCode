#define pb push_back

class Solution {
public:

    void backtrack(vector<int> &a, int i, vector<int> &v, set<vector<int>> &ans){
        if(i == a.size()){
            ans.insert(v);
            return;
        }
        v.pb(a[i]);
        backtrack(a, i+1, v, ans);
        v.pop_back();
        backtrack(a, i+1, v, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> ans1;
        sort(nums.begin(), nums.end());
        vector<int> v;
        backtrack(nums, 0, v, ans1);

        for (auto x : ans1)
            ans.pb(x);
        return ans;
    }
};