class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        int i = 0, j = 0;

        // merging the two array into one
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j]){
                v.push_back(nums1[i]);
                i++;
            }
            else {
                v.push_back(nums2[j]);
                j++;
            }
        }
        while(i < nums1.size()){
            v.push_back(nums1[i]);
            i++;
        }
        while(j < nums2.size()){
            v.push_back(nums2[j]);
            j++;

        }
        
        int n = nums1.size() + nums2.size();
        if(n%2 == 1){
            return v[n/2]*1.0;
        }
        return 1.0*(v[n/2] + v[n/2-1])/2;
    }
};