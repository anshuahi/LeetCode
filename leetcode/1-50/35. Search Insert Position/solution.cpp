class Solution {
public:
    int searchInsert(vector<int>& v, int t) {
        /*  
        --------------LOWER BOUND-----------------
            auto p = lower_bound(v.begin(), v.end(), t);
            return (p-v.begin());
        */

        int s = 0, e = v.size()-1;
        while(s <= e){
            int m = (s+e)/2;
            if(v[m] == t)
                return m;
            if(v[m] < t){
                s = m+1;
            }
            else{
                e = m-1;
            }
        }
        
        return s;
    }
};