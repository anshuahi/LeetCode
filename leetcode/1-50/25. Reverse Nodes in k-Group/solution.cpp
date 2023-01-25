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
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)
            return head;
        
        ListNode* h = head; // saving the head

        // reversing first k elements
        int i = 1;
        ListNode* root = new ListNode(head->val);
        head = head->next;
        ListNode* temp = root;
        while(i < k && head){
            ListNode* t = new ListNode(head->val);
            head = head->next;
            t->next = temp;
            temp = t;
            i++;
        }
        
        // if elements are less than k return list as it is
        if(i < k)
            return h;
        
        if(!head)
            return temp;
        // calling the recursive function remaining elements
        root->next = reverseKGroup(head, k);
        
        return temp;
    }
};