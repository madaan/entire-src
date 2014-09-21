//sg
#include<bits/stdc++.h>
using namespace std;
#define MAX 100009
unsigned int cumxor[MAX];
int main() {
    int t;
    int a, b, temp;
    scanf("%d", &t);
    while(t--) {
        memset(cumxor, 0, sizeof(cumxor));
        int n, q;
        cumxor[0] = 0;
        scanf("%d", &n);
        scanf("%d", &cumxor[1]);
        for(int i = 2; i <= n; i++) {
            scanf("%d", &temp);
            cumxor[i] = temp ^ cumxor[i - 1];
        }
        scanf("%d", &q);
        for(int i = 1; i <= q; i++) {
            scanf("%d%d", &a, &b);
            printf("%d\n", cumxor[b + 1] ^ cumxor[a]);
        }
    }
    return 0;
}
