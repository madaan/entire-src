//sg
#include<stdlib.h>
#include<stdio.h>
typedef long long ll;

ll sumDigs(ll n) {
    int sumDigs = 0;
    while(n) {
        sumDigs = sumDigs + (n % 10);
        n /= 10;
    }
    return sumDigs;
}

ll sumDigsTill(ll n) {
    ll res = 0;
    for(int i = 0; i <= n; i++) {
        res += sumDigs(i);
    }
    return res;
}

int main(int argc, char *argv[]) {
    ll n = atol(argv[1]);
    printf("%lld\n", sumDigsTill(n));
    return 0;
}


