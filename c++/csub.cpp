//sg
#include<cstdio>
#define MAX 100009
typedef long long ll;
ll res(ll numOnes) {
    ll ans = 0;
    if(numOnes % 2 == 0) {
        ans = (numOnes / 2) * (numOnes - 1);
    } else {
        ans = ((numOnes - 1) / 2) * (numOnes);
    }
    return ans + numOnes;
}
char ip[MAX];
int main() {
    int t, n;
    scanf("%d", &t);
    while(t--) {
        ll numOnes = 0;
        scanf("%d", &n);
        scanf("%s", ip);
        for(int i = 0; i < n; i++) {
            if(ip[i] == '1') {
                numOnes++;
            }
        }
        printf("%lld\n", res(numOnes));
    }
    return 0;
}
