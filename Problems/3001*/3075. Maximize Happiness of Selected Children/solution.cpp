/*
LeetCode-POTD: 3075. Maximize Happiness of Selected Children

POTD Link - https://leetcode.com/problems/maximize-happiness-of-selected-children/description/

Approach
    1. use priority_queue
    2. add q.top() and reduce the happiness of the remaining children

*/
class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        long long ans = 0;
        priority_queue<int> q;
        for (auto happy : happiness)
        {
            q.push(happy);
        }
        int i = 0;
        while (!q.empty() && i < k)
        {
            int happy = q.top() - i++;
            q.pop();
            ans += max(happy, 0);
        }
        return ans;
    }
};