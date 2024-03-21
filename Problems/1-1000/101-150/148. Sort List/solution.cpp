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

    ListNode* insert(ListNode* head, int p){
        ListNode* a = new ListNode(p, head);
        return a;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        vector<int> v;

        while(head){
            v.push_back(head->val);
            head = head->next;
        }

        head = NULL;
        sort(v.rbegin(), v.rend());
        for(auto x: v){
            head = insert(head, x);
        }

        return head;
    }
};