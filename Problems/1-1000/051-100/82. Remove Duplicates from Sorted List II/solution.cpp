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
        if(!head || !head->next)
            return head;
        int x = head->val;
        head = head->next;
        int c = 1;
        while(head && head->val == x){  // iterate and check till the node value is equal to first value
            head = head->next;
            c++;
        }
        
        ListNode* l = deleteDuplicates(head);
        if(c == 1){     // add the node only if its consecutive frequency is one
            ListNode* p = new ListNode(x);
            p->next = l;
            return p;
        }
               
        
        return l;
    }
};