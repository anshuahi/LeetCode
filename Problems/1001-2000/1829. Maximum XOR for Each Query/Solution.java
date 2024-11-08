/*
LeetCode-POTD: 1829. Maximum XOR for Each Query

POTD Link - https://leetcode.com/problems/maximum-xor-for-each-query/description

Approach
    1. find XOR of the array, x
    2. from bit 0 to maximumBit, check if ith bit unset of x, add (1 << bit) to k
    3. add k to ans array
    4. remove last element from XOR, repeat (2nd, 3rd and 4th steps)
*/

class Solution {
    public int[] getMaximumXor(int[] nums, int maximumBit) {
        int x = 0;
        for (int n : nums) {
            x = x ^ n;
        }
        int n = nums.length;
        int[] ans = new int[n];
        int j = 0;
        for (int i = n - 1; i >= 0; i--) {
            int k = 0;
            for (int bit = maximumBit - 1; bit >= 0; bit--) {
                if ((x & (1 << bit)) == 0) {
                    k = k + (1 << bit);
                }
            }
            ans[j++] = k;
            x = x ^ nums[i];
        }

        return ans;
    }
}
