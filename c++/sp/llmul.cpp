//sg
#include<bits/stdc++.h>
using namespace std;
struct node 
{
    int exp;
    int coeff;
    node *next;
    node(int exp, int coeff) : exp(exp), coeff(coeff), next(NULL) {
    }

    void dump() {
        node *tmp = this;
        while(tmp ->next) {
            cout << tmp->coeff << " * x^ " << tmp->exp << " + ";
            tmp = tmp -> next;
        }
        cout << tmp->coeff << " * x^ " << tmp->exp;
        cout << "\n";
    }

};


node *mulll(node *p1, node *p2) {
    node *tmp = p1;
    map<int, node*> enodemap;
    for(node *p1_p = p1; p1_p; p1_p = p1_p -> next) {
        for(node *p2_p = p2; p2_p; p2_p = p2_p -> next) {
            int coeff = p1_p->coeff * p2_p -> coeff;
            int exp = p1_p->exp + p2_p -> exp;
            if(enodemap.find(exp) == enodemap.end()) {
                enodemap[exp] = new node(exp, coeff);
            } else {
                enodemap[exp]->coeff += coeff;
            }
        }
    }
    node *res = NULL;
    node *ans;
    for(auto polyterm = enodemap.rbegin(); polyterm != enodemap.rend(); polyterm++) {
        if(res == NULL) {
            res = polyterm->second;
            ans = res;
        } else if(polyterm->second->coeff != 0) {
            res -> next = polyterm->second;
            res = res->next;
        }
    }
    
    return ans;
}


int main() {
    node *p1 = new node(1, 1);
    p1->next = (new node(0, 1));
    node *p2 = new node(1, 1);
    p2->next = new node(0, -1);
    node *res = mulll(p1, p2);
    res->dump();
    return 0;
}
