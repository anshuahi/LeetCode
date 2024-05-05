/*
LeetCode-POTD: 237. Delete Node in a Linked List

POTD Link - https://leetcode.com/problems/delete-node-in-a-linked-list/description/

GitHub Solution Link- https://github.com/anshuahi/LeetCode/blob/main/daily-challenges-2024/05_05_2024.cpp

Approach
   1. simply change the reference value
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        *node = *(node->next);
    }
};
