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
/*
    1. Set 2 pointers slow & fast with strides 1 & 2. 
    2. Traverse till fast reaching the end
    3. reverse the slow->next(second half of the list)
    4. merge the Lists
*/


class Solution {
public:
   
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return;
        // Find the middle of the list
        ListNode* slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        ListNode* prev = NULL, *curr = slow->next, *nextNode;
        while(curr != NULL){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        slow->next = NULL;

        // merge the 2 halves
        ListNode* first = head, *second = prev;
        while(first && second){
            ListNode* first_next = first->next;
            ListNode* second_next = second->next;

            first->next = second;
            second->next = first_next;

            first = first_next;
            second = second_next;
        }
    }
};