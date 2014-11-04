//sg
#include<bits/stdc++.h>
using namespace std;
class Combinator {
    int n;
    int comb[10];
    int avail[10];
    public:
    Combinator(int n, vector< int > unAvail) {
        this -> n = n;
        for(int i = 0; i < 10; i++) avail[i] = 1;
        for(int i = 0, l = unAvail.size(); i < l; i++) {
            avail[unAvail[i]] = 0;
        }
    }
    void printCombs(int pos) {
        if(pos == n) {
            for(int i = 0; i < n; i++) {
                cout << comb[i] << " ";
            }
            cout << "\n";
        }
        for(int i = 0; i < 10; i++) {
            if(avail[i]) {
                avail[i] = 0;
                comb[pos] = i;
                printCombs(pos + 1);
                avail[i] = 1;
            }
        }
    }
};

int main() {
    int unAvail[] = {0,5};
    vector< int > unav(unAvail, unAvail + 2);
    Combinator c(8, unav);
    c.printCombs(0);
    return 0;
}
