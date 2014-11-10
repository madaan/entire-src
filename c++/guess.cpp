//sg
#include<stdio.h>
typedef long long ll;
ll hcf(ll a, ll b) {
    ll temp;
    while(b != 0) {
        temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}
int main() {
    int t;
    ll m, n;
    ll num, den;
    ll even_m, odd_m, even_n, odd_n;
    scanf("%d", &t);
    while(t--) {
        scanf("%lld%lld", &m, &n);

        num = (m / 2) * ((n + 1) / 2) + ((m + 1) / 2) * (n / 2);
        den = m * n;
        ll d_p = 0, nu_p = 0, hcf_nd;
        while(d_p != den || nu_p != num) {
            nu_p = num;
            d_p = den;
            hcf_nd = hcf(num, den);
            num = num / hcf_nd;
            den = den / hcf_nd;
        }
        printf("%lld/%lld\n", num, den);
    }
    return 0;
}
