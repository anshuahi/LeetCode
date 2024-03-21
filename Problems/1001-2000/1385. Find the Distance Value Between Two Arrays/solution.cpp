class Solution {
public:
    int findTheDistanceValue(vector<int>& a1, vector<int>& a2, int d) {
        sort(a2.begin(), a2.end());
        int count = 0;// = a1.size();
        for(auto x: a1){
            auto l = lower_bound(a2.begin(), a2.end(), x-d);
            auto r = upper_bound(a2.begin(), a2.end(), x+d);
            // cout << (l-a2.begin()) << " " << (r-a2.begin()) << endl;
            if(l == r){
                count++;
            }
        }

        return count;
    }
};