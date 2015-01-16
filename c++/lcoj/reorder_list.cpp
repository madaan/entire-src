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
void dumpList(ListNode *ln) {
    while(ln) {
        cout << ln -> val << " ";
        ln = ln -> next;
    }
    cout << "\n";
}
void reorderList(ListNode *head) {
    if(!head) {
        return;
    }
    int n = 0;
    stack<ListNode*> st;
    ListNode *temp = head;
    while(temp) {
        st.push(temp);
        temp = temp->next;
        n++;
    }
    if(n <= 2) {
        return;
    }
    ListNode *ptr = head;
    ListNode *res = ptr;
    ptr = ptr->next;
    res->next = st.top();
    res = res -> next;
    st.pop();
    for(int i = 1; i < n / 2; i++) {
        res->next = ptr;
        ptr = ptr->next;
        res = res->next;
        res->next = st.top();
        st.pop();
        res = res->next;
    }
    if(n % 2) {
        res -> next = st.top();
        res = res->next;
    }
    res->next = NULL;
}
int main() {
    ListNode *n1 = new ListNode(1);
    ListNode *n5 = new ListNode(5);
    ListNode *n2 = new ListNode(2);
    ListNode *n4 = new ListNode(4);
    n1 -> next = n5;
    n5 -> next = n4;
    dumpList(n1);
    reorderList(n1);
    dumpList(n1);
    return 0;
}
