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
    
    ListNode* insert(ListNode* root, int x){
        ListNode* temp = new ListNode(x);
        if(!root){
            return temp;
        }
        ListNode* t = root;
        while(t->next != NULL){
            t = t->next;
        }
        t->next = temp;
        
        return root;
    }
    
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* a, *b;
        a = b = NULL;
        while(head != NULL){
            if(head->val < x){
                a = insert(a, head->val);
            }
            else {
                b = insert(b, head->val);
            }
            head = head->next;
        }
        
        if(!a)
            return b;
        if(!b)
            return a;
        
        ListNode* t = a;
        while(t->next){
            t = t->next;
        }
        t->next = b;
        
        return a;
    }
};