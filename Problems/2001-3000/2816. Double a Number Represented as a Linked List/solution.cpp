/*
LeetCode-POTD: 2816. Double a Number Represented as a Linked List

POTD Link - https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/

Approach
        1. reverse the linked list
        2. double every node's value and forward the carry to the next node.

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
    ListNode *reverse(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *h = NULL;
        while (head)
        {
            h = new ListNode(head->val, h);
            head = head->next;
        }
        return h;
    }

    ListNode *doubleIt(ListNode *head)
    {
        ListNode *p = reverse(head);
        ListNode *t = NULL;
        int carry = 0;
        while (p)
        {
            int x = p->val * 2 + carry;
            t = new ListNode(x % 10, t);
            carry = x / 10;
            p = p->next;
        }
        if (carry > 0)
        {
            t = new ListNode(carry, t);
        }
        return t;
    }
};
