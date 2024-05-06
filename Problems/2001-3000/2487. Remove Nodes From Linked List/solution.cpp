/*
LeetCode-POTD: 2487. Remove Nodes From Linked List

POTD Link - https://leetcode.com/problems/remove-nodes-from-linked-list/description
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNodes(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        stack<int> s;
        while (head)
        {
            int x = head->val;
            while (!s.empty() && s.top() < head->val)
            {
                s.pop();
            }
            s.push(head->val);
            head = head->next;
        }
        ListNode *ans = NULL;
        while (!s.empty())
        {
            ans = new ListNode(s.top(), ans);
            s.pop();
        }
        return ans;
    }
};
