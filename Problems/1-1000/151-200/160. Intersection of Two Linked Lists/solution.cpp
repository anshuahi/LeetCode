/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA, *b = headB;
        int an = 0, bn = 0;
        
        while(a){
            an++;
            a = a->next;
        }
        
        while(b) {
            bn++;
            b = b->next;
        }
        
        if(an > bn){
            int j = an - bn;            
            while(j--){
                headA = headA->next;                
            }
        }
        else {
            int j = bn - an;            
            while(j--){
                headB = headB->next;                
            }
        }
        
        while(headA && headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        
        return headA;
        
    }
};