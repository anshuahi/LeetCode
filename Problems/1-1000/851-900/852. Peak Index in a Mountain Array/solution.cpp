class Solution {
public:
    int peakIndexInMountainArray(vector<int>& v) {
        int n = v.size();
        int st = 0, en = n-1;
        int mid;
        while(st < en){
            mid = (st+en)/2;
            if(mid == 0 || mid == n-1){
                return mid;
            }
            if(v[mid] > v[mid-1] && v[mid] > v[mid+1]){
                return mid;
            }
            if(v[mid] > v[mid-1]){
                st = mid;
            }
            else {
                en = mid;
            }
        }
        return st;
    }
};