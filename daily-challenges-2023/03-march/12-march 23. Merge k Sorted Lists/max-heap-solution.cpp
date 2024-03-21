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
    /*
    Approach use max heap,
    pop element from heap and insert it at the start of list
    Complexity O(nlog(n))   // n is total number of elements
    */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int> q;
        for(int i = 0; i < lists.size(); i++) {
            ListNode* l = lists[i];
            while(l) {
                q.push(l->val);
                l = l->next;
            }
        }
        
        if(q.empty()) {
            return NULL;
        }
        
        int p = q.top();q.pop();
        ListNode* head = new ListNode(p);
        
        while(!q.empty()) {
            p = q.top();
            q.pop();
            ListNode* temp = new ListNode(p);
            temp->next = head;
            head = temp;
        }
        
        return head;
    }
};