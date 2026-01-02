/*

LeetCode-POTD: 66. Plus One

POTD Link - https://leetcode.com/problems/plus-one/description/

LeetCode Solution: https://leetcode.com/problems/plus-one/solutions/7458384/66-plus-one-reverse-traversal-carry-hand-8hh7/

Approach
1. traverse the digits array from last to first
2. if digit is less than 9, increment it by 1 and return the array
3. if digit is 9, set it to 0 and continue to next digit
4. if all digits are 9, create a new array of size n+1 and set the first element to 1
*/

class Solution {
    public int[] plusOne(int[] digits) {
        int n = digits.length;
        for(int i = n-1; i >= 0 && carry > 0; i--){
            if(digits[i] < 9){
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        
        digits = new int[n+1];
        digits[0] = 1;
        return digits;
    }
}
