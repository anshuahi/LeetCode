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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || head->next == NULL)
            return head;
        
        ListNode* h = new ListNode(head->val);
        head = head->next;
        ListNode* t = h;
        
        while(head){
            if(head->val != t->val){
                ListNode* temp = new ListNode(head->val);
                t->next = temp;
                t = t->next;
            }
            head = head->next;
        }
            
        return h;
    }
};