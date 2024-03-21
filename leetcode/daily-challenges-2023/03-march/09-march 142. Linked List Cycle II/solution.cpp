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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next){
            return NULL;
        }
        int x = 1;
        map<ListNode*, int> mp;
        
        while(head){
            if(mp[head] == 0){
                mp[head] = x;
            }
            else {
                return head;
            }
            head = head->next;
            x++;
        }
        
        return NULL;
    }
};