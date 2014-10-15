//sg
#include<bits/stdc++.h>
using namespace std;

struct treenode {
    treenode *left;
    treenode *right;
    int data;
    treenode(int a):data(a) {
    }
};

void preorder_rec(treenode *root) {
    if(root != NULL) {
        cout << root -> data << " ";
        preorder_rec(root -> left);
        preorder_rec(root -> right);
    }
}

void preorder(treenode *root) {
    stack<treenode *> st;
    st.push(root);
    while(!st.empty()) {
        treenode *tn = st.top();
        st.pop();
        cout << tn -> data << " ";
        if(tn->right) st.push(tn->right);
        if(tn->left) st.push(tn->left);
    }
    cout << "\n";
}

size_t sizetree(treenode *node) {
    if(node) {
        return 1 + sizetree(node -> left) + sizetree(node -> right);
    } else {
        return 0;
    }
}

//reverse level order traversal
void rev_lot(treenode *node) {
    if(node == NULL) return;
    queue<treenode *> toProcess;
    stack<treenode *> toPrint;
    toProcess.push(node);
    while(!toProcess.empty()) {
        treenode *curr = toProcess.front();
        toProcess.pop();
        if(curr -> right) toProcess.push(curr -> right);
        if(curr -> left) toProcess.push(curr -> left);
        toPrint.push(curr);
    }
    while(!toPrint.empty()) {
        treenode *curr = toPrint.top();
        toPrint.pop();
        cout << curr -> data << " ";
    }
}

//diameter of a binary tree

int dia_tree(treenode *node) {

}

/*
 *       3
 *  4       5
 *    10       2
 */
int main() {
    treenode * tn = new treenode(3);
    tn -> left = new treenode(4);
    tn -> right = new treenode(5);
    tn -> left -> right = new treenode(10);
    tn -> right -> right = new treenode(2);
    rev_lot(tn);
    return 0;
}
    
