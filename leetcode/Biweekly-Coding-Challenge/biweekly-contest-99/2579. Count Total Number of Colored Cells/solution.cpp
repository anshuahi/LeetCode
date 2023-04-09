// https://leetcode.com/contest/biweekly-contest-99/
// https://leetcode.com/contest/biweekly-contest-99/problems/count-total-number-of-colored-cells/
#define ll long long int
class Solution {
public:
    long long coloredCells(int n) {
        if(n == 1){
            return 1;
        }
        ll p = n;
        ll a = p*p*2 - p*2 +1;
        return a;
    }
};