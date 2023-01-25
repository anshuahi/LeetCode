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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return false;
        }
                
        map<ListNode*, bool> m;
        while(head != NULL){
            if(m[head] == true)
                return true;
            m[head] = true;
            head = head->next;
        }
        
        return false;
    }
};