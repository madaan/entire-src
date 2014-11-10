//sg
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n;
    ll mod = 1000000007;
    scanf("%lld", &n);
    ll b2 = n / 2;
    if(n % 2 == 0) {
        b2--;
    }
    ll res = b2 % mod;
    //printf("%lld\n", res);
    for(int i = 1; i < 6; i++) {
        res = (res * (b2 - i)) % mod;
        res = res % mod;
        //printf("%lld\n", res);
    }
    res = res * 301388891l;
    res = res % mod;
    printf("%lld\n", res);
    return 0;
}
