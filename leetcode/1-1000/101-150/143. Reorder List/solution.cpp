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
#define pb push_back

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next)
            return;
        vector<int> v;
        ListNode* p = head;
        while(p){
            v.pb(p->val);
            p = p->next;
        }
        
        // ListNode* root = new ListNode(v[0]);
        bool c = false;
        int i = 1, e = v.size()-1;
        ListNode* temp = head;
        
        while(i <= e){
            ListNode* t = NULL;
            if(c){
                t = new ListNode(v[i++]);
            }
            else {
                t = new ListNode(v[e--]);
            }
            temp->next = t;
            temp = temp->next;
            c = !c;
        }
        // head = root;
        return;
        
    }
};