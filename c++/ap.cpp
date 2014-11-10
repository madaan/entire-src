//sg
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, temp;
    vector<int> cards;
    scanf("%d", &n);
    if(n == 1) {
        scanf("%d", &n);
        printf("-1\n");
        return 0;
    }
    if(n == 2) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(a > b) {
            a ^= b;
            b ^= a;
            a ^= b;
        }
        if(a == b) {
            printf("1\n%d\n", a);
        } else if(abs(a - b) == 1) {
            printf("2\n%d %d", a - 1, b + 1);
        } else {

            int mid = ((a + b) / 2);
            int d = b - a;
            if(d % 2 == 0) {
                printf("3\n%d %d %d\n",  a - d, mid, b + d);
            } else {
                printf("2\n%d %d\n",  a - d, b + d);
            }
        }
        return 0;
    }
    int invs = 0;
    bool allSame = true;
    scanf("%d", &temp);
    cards.push_back(temp);
    int prev_int = temp;
    for(int i = 0; i < n -1; i++) {
        scanf("%d", &temp);
        if(temp != prev_int) {
            allSame = false;
        }
        cards.push_back(temp);
    }
    sort(cards.begin(), cards.end());
    if(allSame) {
        printf("1\n%d\n", cards[0]);
        return 0;
    }
    int d1 = cards[1] - cards[0];
    int d2 = cards[2] - cards[1];
    int inv = 0;
    int d;
    int locInv = 0;
    if(d1 == d2) {
        d = d1;
    } else {
        inv++;
        if(n > 3) {
            int d3 = cards[3] - cards[2];
            if(d1 == d3) {
                d = d1;
                locInv = 2;
            } else if(d2 == d3) {
                d = d2;
                locInv = 1;
            } else {
                printf("0\n");
                return 0;
            }
        } else if(d1 > d2) {
            d = d2;
            locInv = 1;
        } else {
            d = d1;
            locInv = 2;
        }
    }
    for(int i = 3; i < n; i++) {
        int nd = cards[i] - cards[i - 1];
        if(d != nd) {
            inv++;
            locInv = i;
        }
    }
    if(inv > 1) { //can't do anything about it
        printf("0\n");
        return 0;
    }
    if(inv == 0) { //one at front and one at back
        printf("2\n%d %d\n", cards[0] - d, cards[n - 1] + d);
        return 0;
    }
    if(inv == 1) {
        int mp = (cards[locInv] + cards[locInv - 1]) / 2;
        if(d == (cards[locInv] - mp)) {
            if((cards[locInv] - cards[locInv - 1]) % 2 == 0)
                printf("1\n%d\n", mp);
            else
                printf("0\n");
        } else {
            printf("0\n");
        }
    }
    return 0;
}
