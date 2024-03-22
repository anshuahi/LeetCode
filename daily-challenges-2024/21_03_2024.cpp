#include "linkedList.h"

class Solution {
public:

    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;
        ListNode* p = NULL;

        while(head){
            // insert new node at the beginning
            p = new ListNode(head->val, p);
            head = head->next;
        }
        return p;
    }
    
};
