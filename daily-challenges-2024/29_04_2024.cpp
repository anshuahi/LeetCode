/*
LeetCode-POTD: 2997. Minimum Number of Operations to Make Array XOR Equal to K

POTD Link - https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/description/

*/

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x = 0;
        for(auto n: nums){
            x = x^n;
        }
        int ans = 0;
        while(x || k){
            if(x%2 != k%2) ans++;
            x = x/2;
            k = k/2;
        }
        
        return ans;
    }
};
