//sg
#include<stdio.h>
#define MODN 1000000007
typedef long long ll;
/*
ll gcd(ll a, ll b) {
    ll temp;
    while(b > 0) {
        temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}
void reduce(ll& a, ll& b) {
    ll gcdab = gcd(a, b);
    a = a / gcdab;
    b = b / gcdab;
}
ll C(ll n, ll k) {
    if(n <= 0) {
        return 0;
    }
    ll num = 1, den = 1;
    if(k > n / 2) {
        k = n - k;
    }

    ll numEle, denEle;
    for(ll i = 1; i <= k; i++) {
        numEle = n - k + i;
        denEle = i;
        reduce(numEle, denEle);
        reduce(num, denEle);
        reduce(numEle, den);
        num = (num * numEle) % MODN;
        den = (den * denEle);
    }
    return num / den;
}
*/
ll C(ll n) {
    if(n <= 0) {
        return 0;
    }
    ll res = (((n)) * ((n - 1))) / 2;
    //ll res = (((n) % MODN) * ((n - 1) % MODN)) / 2;
    return res;
}
int main() {
    ll t;
    ll N, a1, a2, b1, b2, c1, c2;
    scanf("%lld", &t);
    ll factor1, factor2;
    while(t--) {
        scanf("%lld", &N);
        scanf("%lld%lld", &a1, &a2);
        scanf("%lld%lld", &b1, &b2);
        scanf("%lld%lld", &c1, &c2);
        if(N > a2 + b2 + c2 || N < a1 + b1 + c1) {
            printf("0\n");
            continue;
        }
        N = N - (a1 + b1 + c1); //get rilld of the lower bounlldary first
        if(N < 0) {
            printf("0\n");
            continue;
        }
        ll a  = a2 - a1 + 1;
        ll b = b2 - b1 + 1;
        ll c = c2 - c1 + 1;
        ll violatingSets = C(N - a + 2) + C(N - b + 2) + C(N - c + 2) - C(N - a - b + 2) - C(N - a - c + 2)- C(N -b - c + 2) + C(N - a - b - c + 2);
        ll ans = (C(N + 2) - violatingSets);
        printf("%lld\n", ans % MODN);
    }
    return 0;
}

