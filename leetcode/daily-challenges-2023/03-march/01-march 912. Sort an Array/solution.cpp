#define pb push_back
class Solution {
public:

    vector<int> merge(vector<int> &a, vector<int> &b){
        int i = 0, j = 0;
        vector<int> v;
        while(i < a.size() && j < b.size()){
            if(a[i] < b[j]){
                v.pb(a[i]);
                i++;
            }
            else {
                v.pb(b[j]);
                j++;
            }
        }
        while(i < a.size()){
            v.pb(a[i]);
            i++;
        }
        while(j < b.size()){
            v.pb(b[j]);
            j++;
        }
        return v;
    }

    vector<int> sortArr(vector<int> &v){
        if(v.size() <= 1)
            return v;
        vector<int> a, b;
        for(int i = 0; i < v.size(); i++){
            if(i < v.size()/2){
                a.pb(v[i]);
            }
            else {
                b.pb(v[i]);
            }
        }
        a = sortArr(a);
        b = sortArr(b);
        return merge(a, b);
    }

    vector<int> sortArray(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        return sortArr(nums);
        // return nums;
    }
};