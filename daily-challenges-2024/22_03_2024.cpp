#include "linkedList.h"

class Solution {
public:

    ListNode* reverseLinkedList(ListNode* head) {
        if(!head){
            return head;
        }
        ListNode* temp = NULL;
        while(head) {
            temp = new ListNode(head->val, temp);
            head = head->next;
        }

        return temp;
    }

    bool isPalindrome(ListNode* head) {
        if(!head){
            return true;
        }

        ListNode* rev = reverseLinkedList(head);
        while(head){
            if(head->val != rev->val)
                return false;
            head = head->next;
            rev = rev->next;
        }
        return true;
    }
};