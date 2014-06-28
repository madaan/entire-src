//sg
#include<stdio.h>
typedef long long ll;

ll getDiv(ll N, int p) {
    if(N == p) {
        return N - 1;
    }
    ll Nb = N;
    ll res = 1, rem;
    while(N) {
        rem = N % p;
        res = res * (rem + 1);
        N = N / p;
    }
    return Nb + 1 - res;
}

int main() {
    int t, p;
    ll N;
    scanf("%d", &t);
    while(t--) {
        scanf("%lld%d", &N, &p);
        printf("%lld\n", getDiv(N, p));
    }
    return 0;
}
