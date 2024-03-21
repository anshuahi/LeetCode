class Solution {
public:
    
    int findPivot(vector<int> nums, int l, int h) {
        if(l > h)
            return -1;
        if(l == h)
            return l;
        int mid = (l + h)/2;
        // mid is not equal to high
        if(mid < h && nums[mid] > nums[mid+1])
            return mid;
        // mid is not equal to low
        if(mid > l && nums[mid] < nums[mid-1]) {
            return mid - 1;
        }
        
        if(nums[l] >= nums[mid])
            return findPivot(nums, l, mid-1);
        
        return findPivot(nums, mid+1, h);
        
    }
    
    // normal binary search
    int binarySearch(vector<int> nums, int l, int h, int key) {
        if(l > h)
            return -1;
        
        int mid = (l + h)/2;
        if(nums[mid] == key)
            return mid;
        
        if(key < nums[mid]){
            return binarySearch(nums, l, mid-1, key);
        }
        return binarySearch(nums, mid+1, h, key);
    } 
    
    int search(vector<int>& nums, int target) {
        // pivot is the point where exists maximum element of the array
        int pivot = findPivot(nums, 0, nums.size()-1);

        // sorted array
        if(pivot == -1)
            return binarySearch(nums, 0, nums.size()-1, target);
        if(nums[0] <= target){  // element exists in first part of array
            return binarySearch(nums, 0, pivot, target);         
        }
        return binarySearch(nums, pivot + 1, nums.size()-1, target);
    }
};