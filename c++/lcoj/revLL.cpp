//sg
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL) {
    }
};

Node *revLL(Node *head, Node **nh) {
    if(head == NULL) {
        return NULL;
    }
    if(head -> next == NULL) {
        *nh = head;
        return head;
    }
    revLL(head->next, nh) -> next = head;
    head->next = NULL;
    return head;
}

void dump(Node *head) {
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
}
    
int main() {
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *res;
    Node **ans = &res;
    n1->next = n2;
    n2->next = n3;
    revLL(n1, ans);
    dump(*ans);
    return 0;
}
