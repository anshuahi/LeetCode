/*
LeetCode-POTD: 1137. N-th Tribonacci Number

POTD Link - https://leetcode.com/problems/n-th-tribonacci-number/description/

Approach :
    1. tribonacci(n) = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3)
*/
class Solution
{
public:
    int tribonacci(int n)
    {
        if (n <= 1)
        {
            return n;
        }
        if (n == 2)
            return 1;
        // recursive solution
        // return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
        vector<int> f(n + 1, 0);
        f[1] = 1;
        f[2] = 1;

        for (int i = 3; i <= n; i++)
        {
            f[i] = f[i - 1] + f[i - 2] + f[i - 3];
        }
        return f[n];
    }
};
