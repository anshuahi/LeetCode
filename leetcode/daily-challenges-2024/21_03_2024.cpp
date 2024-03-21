struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;
        ListNode* p = NULL;

        while(head){
            // insert new node at the beginning
            p = new ListNode(head->val, p);
            head = head->next;
        }
        return p;
    }
    
};
