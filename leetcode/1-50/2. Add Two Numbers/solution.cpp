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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        int x = l1->val + l2->val;
        ListNode* l = new ListNode(x%10);
        int carry = x/10;
        ListNode* temp = l;
        l1 = l1->next;
        l2 = l2->next;
        // using elementary maths
        /*
                6731
               +8909
            =  15640

            iterating one element from each list and adding it, forward carry and save the digit in linked list
        */
        while(l1 && l2){
            x = l1->val + l2->val + carry;
            ListNode* t = new ListNode(x%10);
            carry = x/10;
            temp->next = t;
            l1 = l1->next;
            l2 = l2->next;
            temp = temp->next;
        }
        
        while(l1){
            x = l1->val + carry;
            ListNode* t = new ListNode(x%10);
            carry = x/10;
            temp->next = t;
            l1 = l1->next;
            temp = temp->next;
        }
        
        while(l2){
            x = l2->val + carry;
            ListNode* t = new ListNode(x%10);
            carry = x/10;
            temp->next = t;
            l2 = l2->next;
            temp = temp->next;
        }
        
        if(carry){
            ListNode* t = new ListNode(carry);
            // int carry = x/10;
            temp->next = t;
        }
        
        return l;
    }
};