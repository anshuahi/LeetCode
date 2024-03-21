class Solution {
public:
    int findMin(vector<int>& v) {
        int st = 0, n = v.size();
        int en = n-1;
        int a = v[0];
        while(st <= en){
            int m = (st+en)/2;
            a = min(a, v[m]);
            if(v[m] > v[en]){
                st = m+1;
            }
            else {
                en -= 1;
            }
        }

        return a;
    }
};