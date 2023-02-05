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

    ListNode* insert(ListNode* head, int n){
        if(!head){
            return new ListNode(n);
        }
        ListNode* t = new ListNode(n);
        if(head->val >= n){
            t->next = head;
            return t;
        }
        ListNode* prev = head;
        ListNode* nex = head->next;
        while(nex != NULL){
            if(nex->val > n){
                break;
            }
            nex = nex->next;
            prev = prev->next;
        }
        prev->next = t;
        t->next = nex;
        return head;
    }

    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }

        ListNode* a = nullptr;
        while(head){
            a = insert(a, head->val);
            head = head->next;
        }

        return a;
    }
};











