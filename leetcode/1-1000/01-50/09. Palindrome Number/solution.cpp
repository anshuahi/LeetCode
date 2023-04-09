class Solution {
public:
    bool isPalindrome(int x) {
        int n = x;
        long y = 0;
        while(n > 0){
            y = y*10 + n%10;
            n = n/10;
        }
        return y == x;
    }
};