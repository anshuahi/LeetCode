class Solution {
public:

    void nextPermutation(vector<int>& v) {
        // bool b = next_permutation(v.begin(), v.end());
        int n = v.size();
        int ind = -1;
        for(int i = n-2; i >= 0; i--){
            if(v[i] < v[i+1]){
                ind = i;
                break;
            }
        }
        if(ind == -1){
            reverse(v.begin(), v.end());
            return;
        }
        int nextGreater = v[ind+1];
        int nextGreaterInd = ind+1;
        for(int i = ind+2; i < n; i++){
            if(v[i] < nextGreater && v[i] > v[ind]){
                nextGreaterInd = i;
                nextGreater = v[i];
            }
        }

        swap(v[ind], v[nextGreaterInd]);
        sort(v.begin()+ind+1, v.end());
    }
};