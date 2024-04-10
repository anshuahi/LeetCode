/*
LeetCode-POTD: 950. Reveal Cards In Increasing Order

POTD Link - https://leetcode.com/problems/reveal-cards-in-increasing-order/description/

Approach :
1. sort the deck
2. create a queue and insert index from 0 to n
3. pop the queue, add ans[q.front] = deck[i],
4. pop the queue again, and insert the element at the end.

TimeComplexity: O(N)
SpaceComplexity: O(N)

*/

class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        vector<int> ans(n);
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            q.push(i);
        }

        int i = 0;
        while (i < n)
        {
            int idx = q.front();
            q.pop();
            ans[idx] = deck[i++];
            q.push(q.front());
            q.pop();
        }

        return ans;
    }
};
