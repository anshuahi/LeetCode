#include <iostream>
#include "linkedList.h"
#include "tree.h"

using namespace std;

#define pb push_back
#define pii pair<int, int>

    vector<int> x = {0, 0, -1, 1};
    vector<int> y = {-1, 1, 0, 0};

    // check if a char is vowel
    bool isVowel(char c){
        char c1 = tolower(c);
        return c1 == 'a' || c1 == 'e' || c1 == 'i' || c1 == 'o' || c1 == 'u';
    }

    // binarySearch
    bool binarySearch(vector<int> &arr, int target){
        int st = 0, en = arr.size()-1;

        while(st <= en){
            int mid = (st+en)/2;
            if(target == arr[mid]){
                return true;
            }
            else if(target < mid){
                en = mid-1;
            }
            else {
                st = mid+1;
            }
        }
        return false;
    }

    // overlap using vector<int>
    bool isOverlap(vector<int> &a, vector<int> &b){
        if(a[0] <= b[0] && b[0] <= a[1]){
            return true;
        }
        if(b[0] <= a[0] && a[0] <= b[1]){
            return true;
        }
        return false;
    }

    // overlap using pii<int, int>
    bool isOverlap(pii &a, pii &b){
        if(a.first <= b.first && b.first <= a.second){
            return true;
        }
        if(b.first <= a.first && a.first <= b.second){
            return true;
        }
        return false;
    }

    // reverse a linked-list
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;
        ListNode* p = NULL;

        while(head){
            p = new ListNode(head->val, p);
            head = head->next;
        }
        return p;
    }

int main() {
    return 0;
}