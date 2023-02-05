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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head == NULL)
            return head;
        
        if(left == right){
            return head;
        }
        
        stack<int> s;
        queue<int> q1, q2;
        int i = 1;
        while(i < left){
            // cout << head->val << " . ";
            q1.push(head->val);
            head = head->next;
            i++;
        }
        
        while(i <= right){
            // cout << head->val << " .. ";
            s.push(head->val);
            head = head->next;
            i++;
        }
        
        while(!s.empty()){
            // cout << s.top() << " ";
            q1.push(s.top());
            s.pop();
        }
        
        // while(!q1.empty()){
        //     cout << q1.front() << " ";
        //     q1.pop();
        // }
        // return NULL;
        
        // cout << endl;
        
        while(head){
            // cout << head->val << " ... ";
            q1.push(head->val);
            head = head->next;
            i++;
        }
        
        head = NULL;
        
        head = new ListNode(q1.front());
        q1.pop();
        
        ListNode* temp = head;
        
        while(!q1.empty()){
            // cout << q1.front() << " ";
            ListNode* t = new ListNode(q1.front());
            temp->next = t;
            temp = t;
            q1.pop();
        }
        
        return head;
    }
};