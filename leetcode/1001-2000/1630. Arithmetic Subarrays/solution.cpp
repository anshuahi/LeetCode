class Solution {
public:

    bool isArithmetic(vector<int> &v){
        int n = v.size();
        if(n <= 2)
            return true;
        sort(v.begin(), v.end());
        // for(auto x: v){
        //     cout << x << " ";
        // }
        // cout << endl;
        int d = v[1] - v[0];
        for(int i = 2; i < n; i++){
            if(d != v[i] - v[i-1])
                return false;
        }
        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& v, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i = 0; i < l.size(); i++){
            vector<int> u;
            copy(v.begin()+l[i], v.begin()+r[i]+1, back_inserter(u));
            ans.push_back(isArithmetic(u));
        }
        return ans;
    }
};