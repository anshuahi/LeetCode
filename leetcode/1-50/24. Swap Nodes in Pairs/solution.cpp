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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        // saving first two nodes
        ListNode* t = new ListNode(head->val);
        head = head->next;
        ListNode* t1 = new ListNode(head->val);
        head = head->next;
        // putting second node at first and vice versa
        t1->next = t;
        t->next = swapPairs(head);  // calling recursive function for rest of the list
        
        return t1;
    }
};