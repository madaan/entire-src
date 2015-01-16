//sg
#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l1 == NULL && l2 == NULL) {
            return NULL;
        }
        if(l1 != NULL && l2 == NULL) {
            return l1;
        }
        if(l1 == NULL && l2 != NULL) {
            return l2;
        }
        ListNode *res = new ListNode(0);
        ListNode *head = res;
        int carry = 0;
        while(l1 != NULL && l2 != NULL) {
            //cout << "adding : " << l1->val << " " << l2->val << "\n";
            res->val = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;
            l1 = l1 -> next;
            l2 = l2 -> next;
            if(l1 != NULL && l2 != NULL) {
                res -> next = new ListNode(0);
                res = res -> next;
            }
        }
        //now res is the last node written
        while(l1 != NULL) {
            res->next = new ListNode((l1->val + carry) % 10);
            carry = (l1->val + carry) / 10;
            l1 = l1 -> next;
            res = res -> next;
        }
        while(l2 != NULL) {
            res->next = new ListNode((l2->val + carry) % 10);
            carry = (l2->val + carry) / 10;
            l2 = l2 -> next;
            res = res->next;
        }
        if(carry) {
            res -> next = new ListNode(carry);
        } else {
            res->next = NULL;
        }
        return head;
    }
};
void dumpList(ListNode *ln) {
    while(ln) {
        cout << ln -> val << " ";
        ln = ln -> next;
    }
    cout << "\n";
}
int main() {
    Solution s;
    ListNode *n9 = new ListNode(9);
    ListNode *n1 = new ListNode(1);
    ListNode *n6 = new ListNode(6);
    ListNode *n0 = new ListNode(0);
    n9->next = n1;
    n1->next = n6;
    dumpList(n9);
    dumpList(n0);
    ListNode *ln = s.addTwoNumbers(n0, n9);
    dumpList(ln);
    return 0;
}
    
