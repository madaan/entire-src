//sg
#include<stdio.h>
typedef unsigned long long ll;
ll res(ll n) {
    ll ans = 0;
    ans += ((n) * (n - 1) * (n - 2));
    ans += (2 * (n) * (n - 1) * (n -2) * (n -2));
    ans += (n * (n - 1) * (n - 1) * 2);
    return ans;
}


int main() {
    int t;
    ll n;
    scanf("%d", &t);
    while(t--) {
        scanf("%lld", &n);
        printf("%lld\n", res(n));
    }
    return 0;
}

        
