class Solution {
public:
    int search(vector<int>& a, int x) {
        int s = 0, t = a.size()-1;
        while(s <= t){
            int m = (s+t)/2;
            if(x == a[m]){
                return m;
            }
            else if(x < a[m]){
                t = m-1;
            }
            else {
                s = m+1;
            }
        }
        return -1;
    }
};