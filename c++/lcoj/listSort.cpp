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
    int s;
    Solution() {
        s = 0;
    }
    void breakInTwo(ListNode *head, ListNode **first_half, ListNode **second_half) {
        if(head == NULL) {
            return;
        }
        if(head->next == NULL) {
            *first_half = head;
            *second_half = NULL;
            return;
        }
        ListNode *slow, *fast, *sp;
        slow = fast = head;
        while(fast != NULL && fast -> next) {
            fast = (fast->next)->next;
            sp = slow;
            slow = (slow -> next);
        }
        *second_half = slow;
        sp->next = NULL;
        *first_half = head;
    }
    ListNode *sortList(ListNode *head) {
        if(NULL == head) {
            return NULL;
        }
        ListNode *first_half, *second_half;
        breakInTwo(head, &first_half, &second_half);
        if(second_half == NULL) {
            return first_half;
        }
        return mergeTwoLists(sortList(first_half), sortList(second_half));
    }
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(NULL == l1 && NULL == l2) {
            return NULL;
        } else if(NULL == l2) {
            return l1;
        } else if(NULL == l1) {
            return l2;
        }
        ListNode *head;
        if(l1 -> val < l2 -> val) {
            head = l1;
            l1 = l1 -> next;
        } else {
            head = l2;
            l2 = l2->next;
        }
        ListNode *curr; //last added node
        curr = head;
        while(l1 && l2) {
            if(l1 -> val < l2 -> val) {
                curr -> next = l1;
                curr = l1;
                l1 = l1->next;
            } else {
                curr -> next = l2;
                curr = l2;
                l2 = l2 -> next;
            }
        }
        if(l1 != NULL) {
            curr -> next = l1;
        } else if(NULL != l2) {
            curr -> next = l2;
        } else {
            curr -> next = NULL;
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
    ListNode *n1 = new ListNode(1);
    ListNode *n5 = new ListNode(5);
    ListNode *n4 = new ListNode(4);
    ListNode *n2 = new ListNode(2);
    n1 -> next = n5;
    n5 -> next = n4;
    n4 -> next = n2;
    Solution s;
    dumpList(n1);
    ListNode *ln = s.sortList(n1);
    dumpList(ln);
    return 0;
}
