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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* p = head;
        //  length of the list
        while(p){
            count ++;
            p = p->next;
        }

        p = head;
        if(n > count)
            return head;
        n = count - n;
        if(n == 0){
            return head->next;
        }
        
        ListNode* q = head->next;
        int i = 0;
        // cout << p->val << " " << q->val << endl;
        while(i < n-1) {
            p = p->next;
            q = q->next;i++;
            // cout << p->val << " " << q->val << endl;
        }
        
        p->next = q->next;
        return head;
    }
};