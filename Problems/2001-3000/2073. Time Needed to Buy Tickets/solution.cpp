/*
LeetCode-POTD: 2073. Time Needed to Buy Tickets

POTD Link - https://leetcode.com/problems/time-needed-to-buy-tickets/description

GitHub Solution Link- https://github.com/anshuahi/LeetCode/blob/main/daily-challenges-2024/09_04_2024.cpp

Approach :
    1. people ahead of you should buy atmost tickets[k] tickets.
    2. people behind you should buy atmost tickets[k]-1 tickets.

TimeComplexity: O(N)
SpaceComplexity: O(1)

*/

class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int time = 0;
        int n = tickets.size();
        for (int i = 0; i < n; i++)
        {
            if (i <= k)
            {
                time += min(tickets[k], tickets[i]);
            }
            else
            {
                time += min(tickets[k] - 1, tickets[i]);
            }
        }

        return time;
    }
};
