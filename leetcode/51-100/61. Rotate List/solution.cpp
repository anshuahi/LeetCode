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

    int length(ListNode* l){
        if(!l)
            return 0;
        return 1 + length(l->next);
    }


    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next){
            return head;
        }
        int n = length(head);
        k = k%n;
        if(k == 0){
            return head;
        }

        ListNode* temp = head;
        for(int i =1; i < n-k; i++){
            temp = temp->next;
        }

        ListNode* p = temp->next;
        temp->next = NULL;

        temp = p;

        while(p->next){
            p = p->next;
        }

        p->next = head;

        return temp;

    }
};
